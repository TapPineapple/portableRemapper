#pragma once

#include <Windows.h>
#include <iostream>
#include <functional>


int initPRM();
LRESULT CALLBACK LowLevelKeyboardProc(int nCode, WPARAM wParam, LPARAM lParam);
inline void rmLLHook(HHOOK _hHook);
inline HHOOK initLLHook();
int parseKey(KBDLLHOOKSTRUCT* kbr, WPARAM* wParam);
