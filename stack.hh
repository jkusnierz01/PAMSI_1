#ifndef STACK_HH
#define STACK_HH

#include <iostream>
using namespace std;


template <typename Type>
class stos
{
private:
    int size;
    Type *pointer;
    int iterator;
public:
    stos(int p)
    {
        size = p;                   // rozmar dynamicznej tablicy
        pointer = new Type[size];   // wskaźnik na dynamicznie zadelarowana tablice
        iterator = 0;
    }
    void push(Type number);      // dodanie elementu na stos
    void pop(Type number);      // usuniecie elementu ze stosu
    void show();               //wyswietlenie ostatniego elementu stosu
    void remove_all();        //usuniecie wszystkich elementow stosu
};

template <typename Type>
void stos<Type>::push(Type number)
{
    if(this->iterator<size)
    {
        pointer[this->iterator] = number;
        iterator += 1;
    }
}

template <typename Type>
void stos<Type>::pop(Type number)
{
    pointer[this->iterator -1] = NULL;
    this->iterator -= 1;
}

template <typename Type>
void stos<Type>::show()
{   
    cout << "Ostatni element stosu: " << pointer[this->iterator - 1] << "\n";
}

template <typename Type>
void stos<Type>::remove_all()
{
    for (int i = 0; i < size; i++)
    {
        pointer[i] = NULL;
    }
    iterator = 0;
}


#endif