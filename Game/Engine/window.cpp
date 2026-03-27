#include "window.h"
#include "draw.h"

HWND InitWindow(HINSTANCE hInstance, int width, int height)
{
    const wchar_t CLASS_NAME[] = L"GameWindowClass";

    WNDCLASS wc = { 0 };
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;

    RegisterClass(&wc);

    HWND hwnd = CreateWindowEx(
        WS_EX_TRANSPARENT,
        CLASS_NAME,
        L"GameWindow",
        WS_POPUP | WS_VISIBLE,
        0, 0,
        width,
        height,
        NULL,
        NULL,
        hInstance,
        NULL
    );

    ShowWindow(hwnd, SW_SHOW);
    UpdateWindow(hwnd);

    return hwnd;
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
    case WM_PAINT:
        draw_frame(hwnd);   // ← calls into drawing module
        return 0;

    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }

    return DefWindowProc(hwnd, msg, wParam, lParam);
}
