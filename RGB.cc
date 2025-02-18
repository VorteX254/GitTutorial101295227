#include "RGB.h"

RGB::RGB(int r, int g , int b){
    this->red = r;
    this->green = g;
    this->blue = b;
    //Bounds
    if(r<0 || r > 255){this->red = 0;}
    if(g<0 || g > 255){this->green = 0;}
    if(b<0 || b > 255){this->blue = 0;}

}

RGB::RGB(){
    RGB(0, 0, 0);
}

RGB::RGB(CuColour colour){
    this->red = (colour >> 16) & 0xFF;
    this->green = (colour >> 8) & 0xFF;
    this->blue = colour & 0xFF;
    // Bounds
    if(red<0 || red > 255){red = 0;}
    if(green<0 || green > 255){green = 0;}
    if(blue<0 || blue > 255){blue = 0;}
}

int RGB::getR()const {return red;}
int RGB::getG()const {return green;}
int RGB::getB()const {return blue;}
CuColour RGB::getColour()const{
    return ((red << 16) | (green << 8) | blue);
}

void RGB::setR(int r) {
    if(r<0 || r > 255){return;}
    this->red = r;
}

void RGB::setG(int g) {
    if(g<0 || g > 255){return;}
    this->green = g;
}

void RGB::setB(int b) {
    if(b<0 || b > 255){return;}
    this->blue = b;
}

void RGB::setColour(CuColour colour) {
    setR((colour >> 16) & 0xFF);
    setG((colour >> 8) & 0xFF);
    setB(colour & 0xFF);
}

void RGB::print(){
    std::cout<<"Red: " << red << ", Green: " << green << ", Blue: " << blue << std::endl;
}

RGB RGB::WHITE(){return RGB(255, 255, 255);}
RGB RGB::BLACK(){return RGB(0, 0, 0);}
RGB RGB::RED(){return RGB(255, 0, 0);}
RGB RGB::GREEN(){return RGB(0, 255, 0);}
RGB RGB::BLUE(){return RGB(0, 0, 255);}