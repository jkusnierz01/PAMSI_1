#include "array_stack.hh"


int main() 
{
    int liczba = 0;
    cout << "Podaj rozmiar tablicy: " << "\n";
    cin >> liczba;
    array_stack <int> ob1(liczba);
    ob1.push(33);
    ob1.push(11);
    ob1.show();
    ob1.pop();
    ob1.show();
    ob1.push(2);
    ob1.push(3);
    ob1.remove_all();
    ob1.show();
    return 0;
};




