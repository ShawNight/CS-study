#include <iostream>
#include "Screen.h"
using namespace std;

int main()
{
    Screen s = Screen(5, 5, 'X');
    s.move(4,0).set('#').display(cout);
    cout<< "\n";
    s.display(cout);
    cout << "\n";
    return 0;
}