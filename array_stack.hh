#ifndef ARRAY_STACK_HH
#define ARRAY_STACK_HH
#include <iostream>
using namespace std;


template <typename Type>
class array_stack
{
private:
    int size;
    Type *pointer;          //pointer to dynamic array
    int iterator;
public:
    array_stack(int p)
    {
        size = p;                   // rozmar dynamicznej tablicy
        pointer = new Type[size];   // wskaźnik na dynamicznie zadelarowana tablice
        iterator = 0;
    }
    void push(Type number);      // dodanie elementu na stos
    void pop();      // usuniecie elementu ze stosu
    void show();               //wyswietlenie ostatniego elementu stosu
    void remove_all();        //usuniecie wszystkich elementow stosu
};

template <typename Type>
void array_stack<Type>::push(Type number)
{
    if(this->iterator<size)         //we check if we can still add new element - if we are not out of arrary's range
    {
        pointer[this->iterator] = number;
        iterator += 1;
    }
}

template <typename Type>
void array_stack<Type>::pop()
{
    pointer[this->iterator -1] = 0;
    this->iterator -= 1;
}

template <typename Type>
void array_stack<Type>::show()
{   
    if(this->iterator < 1)
    {
        cout << "Stos pusty!" << "\n";
    }
    else
    {
        cout << "Ostatni element stosu: " << pointer[this->iterator - 1] << "\n";
    }
}

template <typename Type>
void array_stack<Type>::remove_all()
{
    for (int i = 0; i < size; i++)
    {
        pointer[i] = 0;
    }
    iterator = 0;
}

#endif