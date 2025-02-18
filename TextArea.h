#ifndef TEXTAREA_H
#define TEXTAREA_H

#include "RGB.h"
#include <iomanip>

class TextArea{
    private:
        Rectangle dimensions;
        std::string text;
        std::string id;
        RGB fill, border;

    public:
        TextArea(int x, int y, int width, int height, std::string id, std::string label, RGB fill = RGB::WHITE(), RGB border = RGB::BLACK());
        TextArea(Rectangle rectangle, std::string id, std::string label, RGB fill = RGB::WHITE(), RGB border = RGB::BLACK());
        TextArea();
        TextArea(const TextArea &old);

        int getX() const;
        int getY() const;
        int getWidth() const;
        int getHeight() const;
        std::string getText() const;
        std::string getId() const;
        RGB getFill() const;
        RGB getBorder() const;

        void setX(int x);
        void setY(int y);
        void setWidth(int width);
        void setHeight(int height);
        void setText(const std::string &text);
        void setId(const std::string &id);
        void setFill(const RGB &fill);
        void setBorder(const RGB &border);

        bool overlaps(TextArea ta) const;
        void print() const;
};

#endif