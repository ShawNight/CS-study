#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::string;

int main()
{
    vector<string> svec;
    string str;
    while (cin >> str)
    {
        svec.push_back(str);
    }
    return 0;
}
