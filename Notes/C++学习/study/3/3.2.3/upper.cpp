#include <iostream>
#include <string>
int main()
{
    using namespace std;
    string s("Hello World!!!");
    for (auto &c: s)
        c = toupper(c);
    cout << s << endl;
    return 0;
}