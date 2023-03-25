#include "queue.hh"
#include <iostream>

using namespace std;

void run_test(const string nazwa_f, bool funkcja)
{
    cout << nazwa_f;
    if(funkcja)                                         //Sprawdzamy czy funkcja zwrocila True 
    {
        cout << "\tPASSED" << endl;
    }
}

bool TEST_INIT()
{
    queue<int> kolejka;
    assert(kolejka.TopPointer == nullptr);
    assert(kolejka.TailPointer == nullptr);
    return true;
}

//Funkcja sprawdzająca poprawność metody PUSH
bool TEST_PUSH()
{
    queue<int> kolejka;
    kolejka.push(1);
    assert(kolejka.TopPointer == kolejka.TailPointer);
    kolejka.push(2);
    kolejka.push(3);
    assert(kolejka.TopPointer->Value == 1);
    assert(kolejka.TailPointer->Value == 3);
    return true;
}

//Funkcja sprawdzająca poprawność metody POP
bool TEST_POP()
{
    queue<int> kolejka;
    kolejka.pop();
    assert(kolejka.TopPointer == NULL);
    assert(kolejka.TailPointer == NULL);
    kolejka.push(1);
    kolejka.pop();
    assert(kolejka.TopPointer == NULL);
    assert(kolejka.TailPointer == NULL);
    kolejka.push(2);
    kolejka.push(3);
    kolejka.pop();
    assert(kolejka.TopPointer->Value == 3);
    assert(kolejka.TailPointer->Value == 3);
    return true;
}




void TEST()
{
    int il_testow = 3;
    bool func = false;
    cout << endl <<  "Running tests: " << endl;
    for (int i = 1; i < 4; i++)
    {
        switch (i)
        {
        case 1:
            func = TEST_INIT();
            run_test("Test INIT:", func);
            break;    
        case 2:
            func = TEST_PUSH();
            run_test("Test PUSH:", func);
            break;
        case 3:
            func = TEST_POP();
            run_test("Test POP:", func);
            break;
        default:
            break;
        }
    }

    cout << "ALL TEST PASSED" << endl << endl;
}