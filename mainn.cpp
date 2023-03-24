#include "array_stack.hh"
#include "list_stack.hh"
#include <iomanip>


int main() 
{
    clock_t start = clock();
    list_stack<int> ob2;
    ob2.push(100);
    ob2.push(1000);
    ob2.push(10000);
    clock_t end = clock();
    double result  = double(end-start)/CLOCKS_PER_SEC;
    cout << "Czas,ktory uplynal(stos na liscie): " << fixed << setprecision(6) << result << "\n";
    clock_t startt = clock();
    array_stack<int> ob1(3);
    ob2.push(100);
    ob2.push(1000);
    ob2.push(10000);
    clock_t endd = clock();
    double resultt  = double(endd-startt)/CLOCKS_PER_SEC;
    cout << "Czas,ktory uplynal(stos na tablicy): " << fixed << setprecision(7) << resultt << "\n";
    return 0;
};




