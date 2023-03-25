#include "test.cpp"
#include <cstdlib>
#include <unistd.h>


int main() 
{
    TEST();
    bool x=1;
    int size;
    queue<int> kolejka;
    cout << "Podaj ilość elementw w kolejce: ";
    cin >> size;
    int tab[size];
    for (int i = 0; i < size+1; i++)
    {
        tab[i] = rand();
    }
    while(x)
    {
        for (int x = 0; x < size+1; x++)
        {
            float sleep = float(rand()%100*1000);
            usleep(sleep);
            kolejka.push(tab[x]);
            cout << "Rozmiar struktury: " << sizeof(kolejka) << endl;;
            cout << "Ostatni element w kolejce: " << kolejka.TailPointer->Value << endl;
        }
        x=0;
    }
    return 0;
};


/*
Czy aktualny rozmiar skuktury to po prostu wartość zwaraca przez funkcje sizeof()?
W jaki sposob program rowonoczesnie ma wrzucac elementy i wypisywac na ekranie wielkosc stuktury?
"...pobranie najstarszej informacji przechowywanej w strukturze" - wypisać po prostu na ekranie?




*/




