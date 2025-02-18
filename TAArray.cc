#include "TAArray.h"

TAArray::TAArray(){
    size = 0;
    elements = new TextArea*[MAX_COMPONENTS];
}

TAArray::~TAArray(){
    delete [] elements;
}

bool TAArray::add(TextArea* s){
    if (size >= MAX_COMPONENTS)return false;

    elements[size] = s;
    ++size;
    return true;
}

bool TAArray::add(TextArea* s, int index){
    if (size >= MAX_COMPONENTS || index > size || index < 0)return false;

    for(int i = size; i > index; i--){
        elements[i] = elements[i-1];
    }

    elements[index] = s;
    ++size;
    return true;
}


TextArea* TAArray::get(std::string id) const{
    for (int i = 0; i < size; ++i){
        if (elements[i]->getId().compare(id) == 0){
            //std::cout << elements[i]->getId() << std::endl; 
            return elements[i];
        }
    }
    return nullptr;
}

TextArea* TAArray::get(int index) const{
    if (index < 0 || index >= size) return nullptr;
    return elements[index];
}

TextArea* TAArray::remove(std::string name){
    
    int index = 0;
    //std::cout << "id to remove " << id << std::endl;
    //we want to find the index of the element to remove
    while (elements[index]->getId().compare(name) != 0 && index < size){
        //std::cout << "Printed " << index << " "<<elements[index]->getId() << " | ";
        ++index;
    }

    //std::cout<< elements[index]->getId().compare(id) << " " << id << "==" << elements[index]->getId() << std::endl;
    //std::cout << "Removing " << elements[index]->getId() << std::endl;
    //std::cout<<"\n\n\n\n";
    return remove(index);
}

TextArea* TAArray::remove(int index){

    //did we fall off the end of the TAArray?
    if (index<0 || index >=size) return nullptr;

    //we have found what we wanted to remove,
    //assign the output value
    TextArea *text = elements[index];

    //copy everything after index left one position
    while (index < size - 1){
        elements[index] = elements[index + 1];
        ++index;
    }
    --size;
    return text;

}


void TAArray::print()
{
  std::cout << std::endl << std::endl << "TextAreas:" << std::endl;
  for (int i=0; i<size; ++i)
    elements[i]->print();

  std::cout << std::endl;
}