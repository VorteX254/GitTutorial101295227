#include "TextArea.h"

TextArea::TextArea(int x, int y, int width, int height, std::string id, std::string label, RGB fill, RGB border){
    dimensions.x = x;
    dimensions.y = y;
    dimensions.width = width;
    dimensions.height = height;
    this->text = label;
    this->id = id;
    this->fill = fill;
    this->border = border;
}

TextArea::TextArea(Rectangle rectangle, std::string id, std::string label, RGB fill, RGB border){
    dimensions = rectangle;
    this->id = id;
    this->text = label;
    this->fill = fill;
    this->border = border;
}

TextArea::TextArea(){
    dimensions.x = 50;
    dimensions.y = 50;
    dimensions.width = 200;
    dimensions.height = 100;
    this->text = "DEFAULT";
    this->id = "DEFAULT";
    this->fill = RGB::WHITE();
    this->border = RGB::BLACK();
}

TextArea::TextArea(const TextArea &old){
    dimensions = old.dimensions;
    text = "DUPLICATE";
    id = old.id;
    fill = old.fill;
    border = old.border;
}

int TextArea::getX() const{return dimensions.x;}
int TextArea::getY() const{return dimensions.y;}
int TextArea::getWidth() const{return dimensions.width;}
int TextArea::getHeight() const{return dimensions.height;}
std::string TextArea::getText() const{return text;}
std::string TextArea::getId() const{return id;}
RGB TextArea::getFill() const{return fill;}
RGB TextArea::getBorder() const{return border;}

void TextArea::setX(int x){dimensions.x = x;}
void TextArea::setY(int y){dimensions.y = y;}
void TextArea::setWidth(int width){dimensions.width = width;}
void TextArea::setHeight(int height){dimensions.height = height;}
void TextArea::setText(const std::string &text){this->text = text;}
void TextArea::setId(const std::string &id){this->id = id;}
void TextArea::setFill(const RGB &fill){this->fill = fill;}
void TextArea::setBorder(const RGB &border){this->border = border;}

bool TextArea::overlaps(TextArea ta) const{
    return (dimensions.x + dimensions.width > ta.dimensions.x && ta.dimensions.x + ta.dimensions.width > dimensions.x )&&(dimensions.y + dimensions.height > ta.dimensions.y && ta.dimensions.y + ta.dimensions.height > dimensions.y);
}

void TextArea::print() const{
    std::cout << std::left << std::setw(20) <<"TextArea id:" << id << "\n"
    << std::setw(20) << "Preferred location: " << dimensions.x << ", " << dimensions.y << "\n"
    << std::setw(20) << "Size: " << dimensions.width << ", " << dimensions.height << "\n"
    << std::setw(20) << "Text: " << text << std::endl;
}