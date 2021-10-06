#include<fstream>
#include<iostream>
#include<chrono>
#include "HashNew.cpp"

#include "sha256.cpp"
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

    auto start_time = std::chrono::high_resolution_clock::now();
    for(int i =0;i<n;i++)
    {
        
        HashHex(lines[i]);
        
    }
    auto end_time = std::chrono::high_resolution_clock::now();
    auto time = end_time - start_time;

    std::cout << "Mano hash: " << time/std::chrono::milliseconds(1) << "ms.\n";



    start_time = std::chrono::high_resolution_clock::now();
    for(int i =0;i<n;i++)
    {
        sha256(lines[i]);
          
    }
     end_time = std::chrono::high_resolution_clock::now();
     time = end_time - start_time;

    std::cout << "sha256 time: " << time/std::chrono::milliseconds(1) << "ms.\n";
    inp.close();
    system("pause");
    return 0;
}