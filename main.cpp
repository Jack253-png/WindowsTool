#include <iostream>
#include <windows.h>
#include <dwmapi.h>
#include "SRGBColor.h"

using namespace std;

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
    SRGBColor *color = GetWindowsThemeColor();
    cout << color->getBlue() << endl;
}