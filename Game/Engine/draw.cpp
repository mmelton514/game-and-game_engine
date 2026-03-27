#include "draw.h"

static HDC hdc_main;
static HDC hdc_comp;
static DWORD* pixels;
static HBITMAP bitmap;
static BITMAPINFO bmi;

void prepare_screen(HWND hwnd, int width, int height)
{
    ZeroMemory(&bmi, sizeof(bmi));
    bmi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
    bmi.bmiHeader.biWidth = width;
    bmi.bmiHeader.biHeight = -height;
    bmi.bmiHeader.biPlanes = 1;
    bmi.bmiHeader.biBitCount = 32;
    bmi.bmiHeader.biCompression = BI_RGB;

    bitmap = CreateDIBSection(
        GetDC(hwnd),
        &bmi,
        DIB_RGB_COLORS,
        (void**)&pixels,
        0,
        0
    );

    hdc_main = GetDC(hwnd);
    hdc_comp = CreateCompatibleDC(hdc_main);
    SelectObject(hdc_comp, bitmap);

    // Fill with blue for testing
    int count = width * height;
    for (int i = 0; i < count; i++)
        pixels[i] = 0x0000AAFF;
}

void draw_frame(HWND hwnd)
{
    PAINTSTRUCT ps;
    HDC hdc = BeginPaint(hwnd, &ps);

    BitBlt(hdc, 0, 0, bmi.bmiHeader.biWidth, -bmi.bmiHeader.biHeight,
        hdc_comp, 0, 0, SRCCOPY);

    EndPaint(hwnd, &ps);

    RedrawWindow(hwnd, NULL, NULL, RDW_INVALIDATE);
}
