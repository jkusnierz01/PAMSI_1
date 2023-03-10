#include "stack.hh"


int main() 
{
    int liczba = 0;
    cout << "Podaj rozmiar tablicy: " << "\n";
    cin >> liczba;
    stos <int> ob1(liczba);
    ob1.push(33);
    ob1.show();
    return 0;
};




