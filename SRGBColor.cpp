#include "SRGBColor.h"

SRGBColor::SRGBColor(int r, int g, int b) {
    this->red = r;
    this->green = g;
    this->blue = b;
}

SRGBColor::SRGBColor() {
    
}

SRGBColor::~SRGBColor() {

}

SRGBColor::getRed() {
    return this->red;
}

SRGBColor::getGreen() {
    return this->green;
}

SRGBColor::getBlue() {
    return this->blue;
}