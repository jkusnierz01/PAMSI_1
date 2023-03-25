#ifndef QUEUE_HH
#define QUEUE_HH
#include <iostream>
using namespace std;

/*
        STRUKTURA: Element naszej listy jednokierunkowej - dowolnego typu - takiego samego jak kolejka, ktora bedziemy deklarowac
Parametry:
    - pointer na poprzedni element listy - przy konstruowaniu obiektu na NULL
    - wartość ktora deklaruje uzytkownik
*/
template <typename Type>
struct queue_elem
{
    queue_elem* pointer;
    Type Value;
    queue_elem(Type in_value)
    {
        Value = in_value;
        pointer = NULL;
    }
};

/*
Struktura: Kolejka oparta na liście jednokierunkowej
Parametry:
    - wskaxnik na pierwszy element listy
    - wskaznik na ostatni element listy 
Metody:
    - push
    - pop
*/
template <typename QueueType>
struct queue
{
    queue_elem<QueueType>* TopPointer;
    queue_elem<QueueType>* TailPointer;
    queue()                             // konstruktor
    {
        TopPointer = NULL;
        TailPointer = NULL;
    }
    void push(QueueType value);
    void pop();
};

template <typename QueueType>
void queue<QueueType>::push(QueueType value)
{
    if(this->TailPointer == NULL && this->TopPointer == NULL)   //sprawdzamy jest juz jakis element kolejki
    {                                                           //jezeli go nie ma to obydwa wskazniki maja pokazywac na 1 element
        this->TopPointer = new queue_elem<QueueType>(value);
        this->TailPointer = this->TopPointer;
    }
    else                                                       //przy dodawaniu nowego elementu do kolejki laduje on na koncu
    {                                                          //dlatego zmieniamy tylko wskaznik pokazujacy na koniec kolejki
        this->TailPointer->pointer = new queue_elem<QueueType>(value);
        this->TailPointer = this->TailPointer->pointer;
        
    }
}

template <typename QueueType>
void queue<QueueType>::pop()        //usuwanie elementu 1 elementu z kolejki - tego na ktory wskazuje TopPointer
{
    if(this->TopPointer != NULL)                         
    {                                                    //tworzymy wskaznik tymczasowy ktory pokazuje na pierwszy element(ten ktoty ma byc usuniety)
        queue_elem<QueueType>* tmp = this->TopPointer;  
        if (this->TopPointer==this->TailPointer)
        {
            this->TailPointer = this->TopPointer->pointer;
        }       
        this->TopPointer = this->TopPointer->pointer;           //nastepnie wskaznik TopPointer wskazuje na kolejny elelment
        delete tmp;                                             //a element na ktory wskazuje tmp zostaje usuniety
        tmp = NULL;
    }
}



#endif