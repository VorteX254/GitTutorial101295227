#ifndef RGB_H
#define RGB_H

#include "defs.h"
#include <iostream>

class RGB{
    public:
        RGB(int, int, int);
        RGB(CuColour);
        RGB();

        int getR() const;
        int getG() const;
        int getB() const;
        CuColour getColour() const;

        void setR(int);
        void setB(int);
        void setG(int);
        void setColour(CuColour);

        void print();

        static RGB WHITE();
        static RGB BLACK();
        static RGB RED();
        static RGB GREEN();
        static RGB BLUE();

    private:
        int red, green, blue;
};

#endif