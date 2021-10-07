#include<fstream>
#include<iostream>
#include<chrono>
#include<bitset>
//#include"sha256.cpp"
//#include "HashNew.h"
//#include "Hash.cpp"
//#include "MartynoHash.h"
//#include "TomoHash.h"
//#include "VytautoHash.h"
//#include "MargaritosHash.h"
#include "IgnoHash.h"
using namespace std;

int main()
{
    auto start_time = std::chrono::high_resolution_clock::now();
    ifstream inp("randomText2.txt");
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
        getline(inp,b);

        string hashAhex =  hashFun(a);
        string hashBhex=  hashFun(b);

        string HashAbit="";
        string HashBbit="";
        for(int i =0;i<64;i++)
        {
            uint8_t t=0; 
            if(hashAhex[i]>='0'&&hashAhex[i]<='9')
                t = hashAhex[i]-'0';
            if(hashAhex[i]>='a'&&hashAhex[i]<='f')
                t = hashAhex[i]-'a'+10;
            if(hashAhex[i]>='A'&&hashAhex[i]<='F')
                t = hashAhex[i]-'A'+10;
            
            if((t&8)>0)
            {
                HashAbit+='1';
            }
            else
            {
                HashAbit+='0';
            }
            if((t&4)>0)
            {
                HashAbit+='1';
            }
            else
            {
                HashAbit+='0';
            }
            if((t&2)>0)
            {
                HashAbit+='1';
            }
            else
            {
                HashAbit+='0';
            }
            if((t&1)>0)
            {
                HashAbit+='1';
            }
            else
            {
                HashAbit+='0';
            }
        }

        for(int i =0;i<64;i++)
        {
            uint8_t t=0; 
            if(hashBhex[i]>='0'&&hashBhex[i]<='9')
                t = hashBhex[i]-'0';
            if(hashBhex[i]>='a'&&hashBhex[i]<='f')
                t = hashBhex[i]-'a'+10;
            if(hashBhex[i]>='A'&&hashBhex[i]<='F')
                t = hashBhex[i]-'A'+10;
            
            if((t&8)>0)
            {
                HashBbit+='1';
            }
            else
            {
                HashBbit+='0';
            }
            if((t&4)>0)
            {
                HashBbit+='1';
            }
            else
            {
                HashBbit+='0';
            }
            if((t&2)>0)
            {
                HashBbit+='1';
            }
            else
            {
                HashBbit+='0';
            }
            if((t&1)>0)
            {
                HashBbit+='1';
            }
            else
            {
                HashBbit+='0';
            }
        }

        // cout << hashBhex << endl;
        // cout << HashBbit << endl;
        //int bitDiff= (~(Abits^Bbits)).count();
        int bitDiff=0;
        for(int i =0;i<256;i++)
        {
            if(HashAbit[i]!=HashBbit[i])
                bitDiff++;
        }

        bitDiffSum+=bitDiff;
        if(bitMinDiff>bitDiff) bitMinDiff = bitDiff;
        if(bitMaxDiff< bitDiff) bitMaxDiff = bitDiff;
        

        //cout << "Bit difference: " <<bitDiff/256.0*100<<"%"<< endl<<endl;


        int hexDiff=0;
        for(int i =0;i<64;i++)
        {
            uint8_t ta=0; 
            if(hashAhex[i]>='0'&&hashAhex[i]<='9')
                ta = hashAhex[i]-'0';
            if(hashAhex[i]>='a'&&hashAhex[i]<='f')
                ta = hashAhex[i]-'a'+10;
            if(hashAhex[i]>='A'&&hashAhex[i]<='F')
                ta = hashAhex[i]-'A'+10;

            uint8_t tb=0; 
            if(hashBhex[i]>='0'&&hashBhex[i]<='9')
                tb = hashBhex[i]-'0';
            if(hashBhex[i]>='a'&&hashBhex[i]<='f')
                tb = hashBhex[i]-'a'+10;
            if(hashBhex[i]>='A'&&hashBhex[i]<='F')
                tb = hashBhex[i]-'A'+10;

            
            uint8_t tc = abs(ta - tb);
            if(tc>8) tc = 8-(tc-8);

            hexDiff += tc;
        }
        hexDiffSum += hexDiff;
        if(hexMinDiff>hexDiff) hexMinDiff = hexDiff;
        if(hexMaxDiff< hexDiff) hexMaxDiff = hexDiff;


        n++;
        if(n%1000==0)
        {
            cout <<"pair: "<< n<<endl;
            //cout << Abits << endl;
        }
        //if(n>100000)break;
    }

    cout <<bitMinDiff/256.0*100<< "%, " << bitMaxDiff/256.0*100<< "%, " << bitDiffSum/(double)n/256.0*100<<"% | "<< hexMinDiff/(64.0*8.0)*100<< "%, " << hexMaxDiff/(64.0*8.0)*100<< "%, " << hexDiffSum/(double)n/(64.0*8.0)*100<<"% |\n";
    cout << "Bit difference min: " <<bitMinDiff/256.0*100<< "%"<< endl;
    cout << "Bit difference max: " <<bitMaxDiff/256.0*100<< "%"<< endl;
    cout << "Bit difference avg: " <<bitDiffSum/(double)n/256.0*100<<"%"<< endl<<endl;

    cout << "Hex difference min: " <<hexMinDiff/(64.0*8.0)*100<< "%"<< endl;
    cout << "Hex difference max: " <<hexMaxDiff/(64.0*8.0)*100<< "%"<< endl;
    cout << "Hex difference avg: " <<hexDiffSum/(double)n/(64.0*8.0)*100<<"%"<< endl;
    // cout << maxA <<endl;
    // cout << maxB << endl;
    auto end_time = std::chrono::high_resolution_clock::now();
    auto time = end_time - start_time;
    cout << "Uztruko: " << time/std::chrono::milliseconds(1) << "ms.\n";

    inp.close();
    system("pause");
    return 0;
}