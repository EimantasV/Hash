#include <iostream>
#include <fstream>
#include <sstream>
#include<string>
#include <Windows.h>
#include "HashNew.h"
#include <bitset>
#include<unordered_set>

int main()
{
    int collisions=0;
    std::unordered_set<std::string> test;
    test.reserve(10000000);

    std::string temp="a";
    for(int i=0;i<10000000;i++)
    {
        temp = HashHex(temp);

        if(test.find(temp)==test.end())
        {
            test.insert(temp);
        }
        else
        {
            collisions++;
            //cout << "COLLISION: " << a <<endl;
            //break;
        }
    }
    std::cout << collisions <<std::endl;
    std::cout << temp <<std::endl;
    system("pause");
    return 0;
}
