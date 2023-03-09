#include <iostream>
using namespace std;


template <typename Type>
class stos
{
public:
    Type Tablica[1000];
};


int main() {
    stos<int> obiekt1;
    obiekt1.Tablica[10] = 15;
    cout << obiekt1.Tablica[10];
};




