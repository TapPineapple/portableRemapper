#include "prm.h"
#include "colemak.h"

HHOOK hHook{};

LRESULT CALLBACK LowLevelKeyboardProc(int nCode, WPARAM wParam, LPARAM lParam)
{
    if (nCode == HC_ACTION)
    {
        KBDLLHOOKSTRUCT* s_kbrInfo = reinterpret_cast<KBDLLHOOKSTRUCT*>(lParam);

        int ret{ parseKey(s_kbrInfo, &wParam) };
        if (ret)
            return ret;

    }

    return CallNextHookEx(hHook, nCode, wParam, lParam);
}

inline void rmLLHook(HHOOK _hHook)
{
    UnhookWindowsHookEx(_hHook);
}

inline HHOOK initLLHook()
{
    return SetWindowsHookEx(WH_KEYBOARD_LL, &LowLevelKeyboardProc, GetModuleHandle(NULL), NULL);
}


int parseKey(KBDLLHOOKSTRUCT* kbr, WPARAM* wParam)
{
    if (umColemak.find(kbr->vkCode) != umColemak.end())
    {
        DWORD newKey = umColemak.at(kbr->vkCode);

        switch (*wParam)
        {
        case WM_KEYDOWN:
        {
            std::cout << "[*] Key down" << std::endl;

            rmLLHook(hHook);
            keybd_event(newKey, 0x1D, KEYEVENTF_EXTENDEDKEY | 0, 0);
            hHook = initLLHook();

            break;
        }
        case WM_KEYUP:
        {
            std::cout << "[*] Key up" << std::endl;

            rmLLHook(hHook);
            keybd_event(newKey, 0x1D, KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0);
            hHook = initLLHook();
            return 1;

            break;
        }
        default:
            *wParam = WM_SYSKEYDOWN; // if you do not specify it changes back to alt
            break;
        }
        return 1;
    }
    return 0;
}


int initPRM()
{
    SetConsoleTitle(L"Colemak Remapper - tap#0061");
    

    hHook = initLLHook();
    if (hHook == NULL)
    {
        std::cout << "[*] Error" << std::endl;
        return -1;
    }
    
    MSG messages;
    
    while (GetMessage(&messages, NULL, 0, 0))
    {
        TranslateMessage(&messages);
        DispatchMessage(&messages);
    }
    
    return 0;
}

    
