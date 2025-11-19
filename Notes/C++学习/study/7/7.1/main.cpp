#include <iostream>
#include <string>
#include "Sales_data.h"

int main()
{
    Sales_data s1 = Sales_data("A0001", 5, 2.0);
    s1.print(std::cout, s1);
    return 0;
}