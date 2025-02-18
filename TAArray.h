#ifndef TAARRAY_H
#define TAARAAY_H

#include "TextArea.h"

class TAArray
{
  public:
    TAArray();
    ~TAArray();

    bool add(TextArea* s);
    bool add(TextArea* s, int index);
    
    TextArea* get(std::string id) const;
    TextArea* get(int index) const;

    TextArea* remove(std::string id);
    TextArea* remove(int index);


    bool isFull(){return size == MAX_COMPONENTS;}
    int getSize(){return size;}
    void print();
    

  private:
    TextArea** elements;
    int size;
   
};

#endif