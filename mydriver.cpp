#include <iostream>
#include "List.h"

using namespace cop4530;

int main()
{
    List<int> list;

    int num = 10;

    while(--num)
    {
       list.push_front(num * 100);
    }

    list.pop_back();
    list.pop_front();
    list.print(std::cout, ' ');
    std::cout << std::endl;
    list.push_back(900);
    list.push_front(100);
    list.print(std::cout, ' ');
    
    return 0;
}