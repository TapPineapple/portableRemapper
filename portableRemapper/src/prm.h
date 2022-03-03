#pragma once

#include <Windows.h>
#include <iostream>
#include <functional>


int initPRM();
LRESULT CALLBACK LowLevelKeyboardProc(int nCode, WPARAM wParam, LPARAM lParam);
inline void rmLLHook(HHOOK _hHook);
inline HHOOK initLLHook();
void inline updateKeyPress(DWORD vkCode, DWORD keyStatus);
int parseKey(KBDLLHOOKSTRUCT* kbr, WPARAM* wParam);
