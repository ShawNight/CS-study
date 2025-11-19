#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

int main()
{
    vector<int> ivec = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int>::iterator iter1 = ivec.begin(), iter2 = ivec.end();
    while (iter1 != iter2)
    {
        cout << *iter1++ << " ";
    }

    return 0;
}