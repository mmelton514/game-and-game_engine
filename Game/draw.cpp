#ifndef UNICODE
#define UNICODE
#endif

#ifndef _UNICODE
#define _UNICODE
#endif

#include <windows.h>
#include <draw.h>

HDC hdc_main; 
HDC hdc_comp; 

DWORD* window_bmp_p;


HBITMAP whole_screen; 
BITMAPINFO bmi; 


PAINTSTRUCT ps;

int screenw = GetSystemMetrics(SM_CXSCREEN);
int screenh = GetSystemMetrics(SM_CYSCREEN);

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

void MakeBitMap(HWND hwnd, HBITMAP* Bitmap, BITMAPINFO Bmi, DWORD** window_p, int Width, int Height)
{
	Bmi.bmiHeader.biSize = sizeof(Bmi.bmiHeader);
	Bmi.bmiHeader.biWidth = Width;
	Bmi.bmiHeader.biHeight = -Height;
	Bmi.bmiHeader.biPlanes = 1;
	Bmi.bmiHeader.biBitCount = GetDeviceCaps(GetDC(hwnd), BITSPIXEL);
	Bmi.bmiHeader.biCompression = BI_RGB;
	Bmi.bmiHeader.biSizeImage = 0;
	Bmi.bmiHeader.biXPelsPerMeter = 0;
	Bmi.bmiHeader.biYPelsPerMeter = 0;
	Bmi.bmiHeader.biClrUsed = 0;
	Bmi.bmiHeader.biClrImportant = 0;

	*Bitmap = CreateDIBSection
	(
		GetDC(hwnd),
		&Bmi,
		DIB_RGB_COLORS,
		(void**)window_p,
		0,
		0
	);

	GetDIBits
	(
		GetDC(hwnd),
		*Bitmap,
		0,
		Height,
		*window_p,
		&Bmi,
		DIB_RGB_COLORS
	);

	DWORD* ws_cpy = *window_p; 
	int MapSize = Width * Height; 
	for (int c = 0; c < MapSize; c++) ws_cpy[c] = 0x0000aaff; 
}

void Prepare_Screen(HWND hwnd)
{
	MakeBitMap(hwnd, &whole_screen, bmi, &window_bmp_p, screenw, screenh);
	hdc_main = GetDC(hwnd);
	hdc_comp = CreateCompatibleDC(hdc_main);
	SelectObject(hdc_comp, whole_screen);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR pCmdLine, int nCmdShow)
{
	const wchar_t CLASS_NAME[] = L"TheWindowClass";

	WNDCLASS wc = { 0 };

	wc.lpfnWndProc = WindowProc;
	wc.hInstance = hInstance;
	wc.lpszClassName = CLASS_NAME;

	RegisterClass(&wc);

	HWND hwnd = CreateWindowEx(
		WS_EX_TRANSPARENT, 
		CLASS_NAME,                     
		L"YT_Tutorial",					
		WS_POPUP | WS_VISIBLE,			

		0, 0,
		GetSystemMetrics(SM_CXSCREEN), 
		GetSystemMetrics(SM_CYSCREEN), 

		NULL,       
		NULL,      
		hInstance,  
		NULL        
	);

	Prepare_Screen(hwnd);

	ShowWindow(hwnd, nCmdShow);

	MSG msg = { 0 };
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return 0;
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	BitBlt(BeginPaint(hwnd, &ps), 0, 0, screenw, screenh, hdc_comp, 0, 0, SRCCOPY);
	EndPaint(hwnd, &ps);

	RedrawWindow(hwnd, NULL, NULL, RDW_INVALIDATE);

	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}