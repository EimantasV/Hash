#include<fstream>
#include<iostream>
#include<chrono>
#include<bitset>
#include "HashNew.cpp"
using namespace std;

int main()
{
    auto start_time = std::chrono::high_resolution_clock::now();
    ifstream inp("konstitucija.txt");
    int n=0;
    int bitMinDiff=256;
    int bitMaxDiff=0;
    int bitDiffSum=0;
    int hexMinDiff=64*16;
    int hexMaxDiff=0;
    int hexDiffSum=0;
    // string maxA;
    // string maxB;
    while(!inp.eof())
    {
        string a,b;
        getline(inp,a);
        //getline(inp,a);
        getline(inp,b);
        // string hashAbit = Hash(a,true);
        // string hashBbit = Hash(b,true);
        uint8_t * hashAbit = HashRaw(a);
        uint8_t * hashBbit = HashRaw(b);
        bitset<256> Abits;
        bitset<256> Bbits;
        for(int i =0;i<32;i++)
        {
            Abits ^= hashAbit[i];
            Abits <<= 8;
            Bbits ^= hashBbit[i];
            Bbits <<= 8;
        }
        // string hashAhex = Hash(a,false);
        // string hashBhex = Hash(b,false);

        int bitDiff= (~(Abits^Bbits)).count();
        //int bitDiff=0;
        // for(int i =0;i<256;i++)
        // {
        //     if(hashAbit[i]!=hashBbit[i])
        //         bitDiff++;
        // }
        bitDiffSum+=bitDiff;
        if(bitMinDiff>bitDiff)bitMinDiff = bitDiff;
        if(bitMaxDiff< bitDiff){
            bitMaxDiff = bitDiff;
            // maxA = hashAbit;
            // maxB = hashBbit;
        }
        //cout << "Bit difference: " <<bitDiff/256.0*100<<"%"<< endl<<endl;
        delete[] hashAbit;
        delete[] hashBbit;

        // int hexDiff=0;
        // for(int i =0;i<64;i++)
        // {
        //     int a =((hashAhex[i]<='9')?((int)hashAhex[i]-'0'):(int)hashAhex[i]-'a'+10);
        //     int b =((hashBhex[i]<='9')?((int)hashBhex[i]-'0'):(int)hashBhex[i]-'a'+10);
        //     hexDiff += abs(a-b);
        // }
        // hexDiffSum += hexDiff;
        // if(hexMinDiff>hexDiff) hexMinDiff = hexDiff;
        // if(hexMaxDiff< hexDiff) hexMaxDiff = hexDiff;


        n++;
        if(n%1000==0)
        {
            cout <<"pair: "<< n<<endl;
            //cout << Abits << endl;
        }
        //if(n>100000)break;
    }

    cout << "Bit difference min: " <<bitMinDiff/256.0*100<< "%"<< endl;
    cout << "Bit difference max: " <<bitMaxDiff/256.0*100<< "%"<< endl;
    cout << "Bit difference avg: " <<bitDiffSum/(double)n/256.0*100<<"%"<< endl<<endl;

    // cout << "Hex difference min: " <<hexMinDiff/(64.0*15.0)*100<< "%"<< endl;
    // cout << "Hex difference max: " <<hexMaxDiff/(64.0*15.0)*100<< "%"<< endl;
    // cout << "Hex difference avg: " <<hexDiffSum/100000.0/(64.0*15.0)*100<<"%"<< endl;
    // cout << maxA <<endl;
    // cout << maxB << endl;
    auto end_time = std::chrono::high_resolution_clock::now();
    auto time = end_time - start_time;
    cout << "Uztruko: " << time/std::chrono::milliseconds(1) << "ms.\n";

    inp.close();
    system("pause");
    return 0;
}