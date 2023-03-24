#include "array_stack.hh"
#include "list_stack.hh"
#include "queue.hh"
#include <cstdlib>
#include <unistd.h>


int main() 
{
    bool x=1;
    int size;
    int tab[size];
    queue<int> kolejka;
    cout << "Podaj ilość elementw w kolejce: ";
    cin >> size;
    for (int i = 0; i < size+1; i++)
    {
        tab[i] = rand();
    }
    while(x)
    {
        for (int x = 0; x < size+1; x++)
        {
            usleep(rand()%2*1000000);
            kolejka.push(tab[x]);
            cout << "Rozmiar struktury" << sizeof(kolejka);
        }
        
    }
};




