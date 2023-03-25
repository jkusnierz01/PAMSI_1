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
    queue_elem *pointer;
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
    queue_elem<QueueType> *TopPointer;
    queue_elem<QueueType> *TailPointer;
    queue() // konstruktor
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
    if (this->TailPointer == NULL && this->TopPointer == NULL) // sprawdzamy jest juz jakis element kolejki
    {
        try
        {
            this->TopPointer = new queue_elem<QueueType>(value);
        }
        catch (bad_alloc &e) // w przypadku błedu z alokowaniem pamieci funkcja zglosi wyjatek std::bad_alloc
        {
            cerr << "Blad alokacji " << e.what() << '\n'; // wyjscie diagnostyczne do wypisywania bledow
        }
        this->TailPointer = this->TopPointer; // jezeli go nie ma to obydwa wskazniki maja pokazywac na 1 element
    }
    else
    {
        try
        {
            this->TailPointer->pointer = new queue_elem<QueueType>(value);
        }
        catch (bad_alloc &e)
        {
            cerr << "Blad alokacji " << e.what() << '\n';
        }

        this->TailPointer = this->TailPointer->pointer;
    }
}

template <typename QueueType>
void queue<QueueType>::pop() 
{
    if (this->TopPointer != NULL)
    { 
        queue_elem<QueueType> *tmp = this->TopPointer;  // tworzymy wskaznik tymczasowy ktory pokazuje na pierwszy element(ten ktory ma byc usuniety)
        if (this->TopPointer == this->TailPointer)      //sprawdzamy czy jest tylko jeden element w kolejce
        {
            this->TailPointer = this->TopPointer->pointer;          //jezeli tak to nasz tylni wskaznik tez musi wskazywać na NULL
        }
        this->TopPointer = this->TopPointer->pointer; // nastepnie wskaznik TopPointer wskazuje na kolejny elelment
        delete tmp;                                   // a element na ktory wskazuje tmp zostaje usuniety
        tmp = NULL;
    }
}

#endif