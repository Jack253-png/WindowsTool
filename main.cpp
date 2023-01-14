#include <iostream>
#include <windows.h>
#include <dwmapi.h>
#include "SRGBColor.h"

using namespace std;

BOOL CALLBACK EnumWindowsProc(HWND hwnd, LPARAM lParam)							
{
	char szBuf[MAX_PATH] = { 0 };
	char szOutput[MAX_PATH] = { 0 };
 
	GetWindowText(hwnd, szBuf, MAX_PATH);
	if (strlen(szBuf))
	{
        printf(szBuf);
        printf("\n");
	}
 
	return(TRUE);
}

SRGBColor* GetWindowsThemeColor() {
    DWORD crColorization;
    BOOL fOpaqueBlend;
    HRESULT result = DwmGetColorizationColor(&crColorization, &fOpaqueBlend);
    if (result == S_OK)
    {
        int r, g, b;
        r = (crColorization >> 16) % 256;
        g = (crColorization >> 8) % 256;
        b = crColorization % 256;
        return new SRGBColor(r, g, b);
    }
    return new SRGBColor();
}

int main(int argc, char *argv[]) {
    EnumWindows(EnumWindowsProc, NULL);
    SRGBColor *color = GetWindowsThemeColor();
    cout << color->getBlue() << endl;
}