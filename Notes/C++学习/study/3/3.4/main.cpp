#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s1,s2;
    cin >> s1 >> s2;
    if (s1 == s2)
        cout << s1 << endl;
    else if (s1 >s2)
        cout << s1 << endl;
    else
        cout << s2 << endl;

    if (s1.length() >= s2.length() )
        cout << s1 << endl;
    else
        cout << s2 << endl;
    return 0;
}