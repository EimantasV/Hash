#include<fstream>
#include<iostream>
#include<chrono>
#include "Hash.cpp"
using namespace std;

int main()
{
    auto start_time = std::chrono::high_resolution_clock::now();
    ifstream inp("randomText2.txt");
    int n=0;
    int collisions=0;
    while(!inp.eof())
    {
        string a,b;
        getline(inp,a);
        getline(inp,b);
        if(Hash(a,false)==Hash(b,false))
        {
            collisions++;
            cout << "COLLISION line: "<< n*2<<endl;
            break;
        }
        n++;
        if(n%1000==0)
        {
            cout <<"line: "<< n<<endl;
        }
    }

    cout << "Collisions: " << collisions<<endl;
    auto end_time = std::chrono::high_resolution_clock::now();
    auto time = end_time - start_time;
    cout << "Uztruko: " << time/std::chrono::milliseconds(1) << "ms.\n";

    inp.close();
    system("pause");
    return 0;
}