#include <iostream>
#include <string>
int main()
{
    using namespace std;
    string s("Hello World!!!");
    decltype(s.size()) punct_cnt = 0;
    for (auto c: s)
        if (ispunct(c))
            ++punct_cnt;
    cout << punct_cnt << " punctuation characters in " << s << endl;
}