#include "array_stack.hh"
#include "list_stack.hh"


int main() 
{
    // int liczba = 0;
    // cout << "Podaj rozmiar tablicy: " << "\n";
    // cin >> liczba;
    // array_stack <int> ob1(liczba);
    list_stack<int> ob2;
    ob2.push(22);
    ob2.push(55);
    ob2.show();
    ob2.pop();
    ob2.show();
    ob2.push(222);
    ob2.push(535);
    ob2.remove_all();
    ob2.show();
    return 0;
};




