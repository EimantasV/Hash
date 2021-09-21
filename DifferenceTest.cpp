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
    int bitMinDiff=256;
    int bitMaxDiff=0;
    int bitDiffSum=0;
    int hexMinDiff=64;
    int hexMaxDiff=0;
    int hexDiffSum=0;
    string maxA;
    string maxB;
    while(!inp.eof())
    {
        string a,b;
        getline(inp,a);
        getline(inp,b);
        string hashAbit = Hash(a,true);
        string hashBbit = Hash(b,true);
        // string hashAhex = Hash(a,false);
        // string hashBhex = Hash(b,false);

        int bitDiff=0;
        for(int i =0;i<256;i++)
        {
            if(hashAbit[i]!=hashBbit[i])
                bitDiff++;
        }
        bitDiffSum+=bitDiff;
        if(bitMinDiff>bitDiff)bitMinDiff = bitDiff;
        if(bitMaxDiff< bitDiff){
            bitMaxDiff = bitDiff;
            maxA = hashAbit;
            maxB = hashBbit;
        }

        // int hexDiff=0;
        // for(int i =0;i<64;i++)
        // {
        //     hexDiff += abs((int)hashAhex[i]-(int)hashBhex[i]);
        // }


        n++;
        if(n%1000==0)
        {
            cout <<"pair: "<< n<<endl;
        }
    }

    cout << "Bit difference min: " <<bitMinDiff/256.0*100<< "%"<< endl;
    cout << "Bit difference max: " <<bitMaxDiff/256.0*100<< "%"<< endl;
    cout << "Bit difference avg: " <<bitDiffSum/100000.0/256.0*100<<"%"<< endl;
    cout << maxA <<endl;
    cout << maxB << endl;
    auto end_time = std::chrono::high_resolution_clock::now();
    auto time = end_time - start_time;
    cout << "Uztruko: " << time/std::chrono::milliseconds(1) << "ms.\n";

    inp.close();
    system("pause");
    return 0;
}