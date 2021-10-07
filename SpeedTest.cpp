#include<fstream>
#include<iostream>
#include<chrono>
#include "HashNew.h"
#include "Hash.cpp"
#include "sha256.cpp"
#include "MartynoHash.h"
#include "TomoHash.h"
using namespace std;

int main()
{
    ifstream inp("konstitucija.txt");
    string lines[1000];
    int n=0;
    while(!inp.eof())
    {    
        getline(inp,lines[n]);
        n++;
    }
    cout << my_hash(lines[0]) << endl;
    std::chrono::nanoseconds time;
    for(int i=0;i<100;i++)
    {
        auto start_time = std::chrono::high_resolution_clock::now();
        for(int i =0;i<n;i++)
        {
            
            TomoHash(lines[i]);
            
        }
        auto end_time = std::chrono::high_resolution_clock::now();
        time += end_time - start_time;
    }

    std::cout << "hash: " << time/100/std::chrono::microseconds(1) << " microsec.\n";


    inp.close();
    system("pause");
    return 0;
}