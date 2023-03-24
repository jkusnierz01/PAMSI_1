#ifndef LIST_STACK_HH
#define LIST_STACK_HH
#include <iostream>
using namespace std;
/*
        KLASA: Element naszej listy jednokierunkowej - dowolnego typu - takiego samego jak stos, ktory bedziemy deklarowac
Parametry:
    - pointer na poprzedni element listy - przy konstruowaniu obiektu na NULL
    - wartość ktora deklaruje uzytkownik
*/
template<typename Type>
class list_element
{
public:
    list_element *pointer;
    Type value;
    list_element(Type v)
    {
        pointer = NULL;
        value = v;
    };
};

/*
KLASA: Stos opartu na liście jednokierunkowej
Parametry:
    - wskaznik na element list o zadeklarowanym typie
Metody:
    - push
    - pop
    - show
    - remove all
*/
template<typename Type2>
class list_stack
{
private:
    list_element<Type2>* TopPointer;
public:
    list_stack()                    //konstruktor - utworzenie wskaznika na obiekt typu element_listy
    {
        TopPointer = NULL;
    };
    void push(Type2 number);        // dodanie elementu na stos
    void pop();                     // usuniecie elementu ze stosu
    void show();                    //wyswietlenie ostatniego elementu stosu
    void remove_all();              //usuniecie wszystkich elementow stosu

};

template <typename Type2>
void list_stack<Type2>::push(Type2 number)
{
    list_element<Type2>* tmp = this->TopPointer;        //wskaznik pomocniczy - aby nowy element stosu wskazywał na poprzedni
    this->TopPointer = new list_element<Type2>(number);
    this->TopPointer->pointer = tmp;
}

template <typename Type2>
void list_stack<Type2>::pop()
{
    list_element<Type2>* tmp = this->TopPointer; 
    this->TopPointer = this->TopPointer->pointer;
    delete tmp;
}

template <typename Type2>
void list_stack<Type2>::show()
{   
    if (this->TopPointer != NULL)
{
    cout << "Ostatni element stosu to: " << this->TopPointer->value << "\n";
}
}

template <typename Type2>
void list_stack<Type2>::remove_all()
{
while (this->TopPointer != NULL)
{
    this->pop();
}
}

#endif
