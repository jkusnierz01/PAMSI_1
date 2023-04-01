#include "test.cpp"
#include <cstdlib>
#include <unistd.h>


int main() 
{
    TEST();
    bool x=true;
    int size = 0;
    int actual_size = 0;
    int wybor;
    int random_number;
    queue<int> kolejka;
    queue_elem<int> element(2);
    int struct_size = 0;
    while(x)
    {
        cout << "Wybierz co chcesz zrobic:" << endl 
        << "1. Dodaj elementy do kolejki" << endl
        << "2. Sprawdz wielkosc kolejki" << endl
        << "3. Wypisz ostatni element kolejki" << endl
        << "4. Usun elementy kolejki" << endl
        << "5. Koniec" << endl << endl;
        cin >> wybor;
        switch (wybor)
        {
        case 1:
            cout << "Podaj ilość elementow do dodania: ";
            cin >> size;
            for (int i = 0; i < size; i++)
                {
                    random_number = rand();
                    kolejka.push(random_number);
                }
            actual_size += size;
            break;
        case 2:
            struct_size = sizeof(kolejka) + sizeof(element)*actual_size;
            cout << "Wielkosc struktury to: " << struct_size << "B" << endl;
            break;
        case 3:
            if(kolejka.TopPointer == 0)
            {
                cerr << "Blad, pusta kolejka!!" << endl << endl;
                break;
            }
            else
            { 
                cout << "Ostatni element kolejki: " << kolejka.TopPointer->Value << endl;
                break;
            }
        case 4:
            cout << "Podaj ilość elementow do usuniecia: "
            ;
            cin >> size;
            for (int i = 0; i < size; ++i)
                {   
                    if(kolejka.TailPointer == 0)
                    {
                        cerr << "Blad, pusta kolejka!!" << endl << endl;
                        break;
                    }
                    else
                    {
                    kolejka.pop();
                    actual_size -= 1;   
                    }   
                }
            break;
        case 5:
            x = false;
            break;
        default:
            break;
        }
    
    }
    return 0;
};


/*
Czy aktualny rozmiar skuktury to po prostu wartość zwaraca przez funkcje sizeof()?
W jaki sposob program rowonoczesnie ma wrzucac elementy i wypisywac na ekranie wielkosc stuktury?
"...pobranie najstarszej informacji przechowywanej w strukturze" - wypisać po prostu na ekranie?


rozmiar to sizeof kolejki i rozmiar sizeof kazdego z elementow
interfejs moze wygladac tak ze mamy do wyboru jedna z opcji o wzroceniu najstarszego, wyswietlenie rozmiaru itd.
test wygląda tak ze wrzucamy 50 mil elementow usuwam 30 milionow i patrze jaki jest rozmiar struktury 

czy jest mozliwosc wyswietlania dynamicznego rozmiaru 

*/




