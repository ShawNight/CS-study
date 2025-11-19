#include <iostream>
#include <vector>
#include <list>
#include <string>

using namespace std;
int main() {
    list<const char*> l{"adada", "dad"};
    vector<string> vec;
    vec.assign(l.begin(), l.end());
}