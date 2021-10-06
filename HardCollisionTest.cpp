#include<fstream>
#include<iostream>
#include<chrono>
#include<unordered_set>
#include "HashNew.cpp"
using namespace std;

int main()
{
    auto start_time = std::chrono::high_resolution_clock::now();
    ifstream inp("randomText3.txt");
    int n=0;
    int collisions=0;
    unordered_set<string> test;
    test.reserve(1000000);
    while(!inp.eof())
    {
        string a;
        getline(inp,a);
        //bool collision =true;
        // if(test.find(HashHex(a))==test.end())
        // {
        //     test.insert(HashHex(a));
        // }
        // else
        // {
        //     collisions++;
        //     //cout << "COLLISION: " << a <<endl;
        //     //break;
        // }

        if(test.find(HashHex(a))==test.end())
        {
            test.insert(HashHex(a));
        }
        else
        {
            collisions++;
            //cout << "COLLISION: " << a <<endl;
            //break;
        }


        n++;
        if(n%10000==0)
        {
            cout <<"line: "<< n<<endl;
        }
        //if(n>100000)break;
    }


    cout << "Collisions: " << collisions<<endl;
    auto end_time = std::chrono::high_resolution_clock::now();
    auto time = end_time - start_time;
    cout << "Uztruko: " << time/std::chrono::milliseconds(1) << "ms.\n";

    inp.close();

    // cout << "\nAll elements : ";
    // unordered_set<string> :: iterator itr;
    // for (itr = test.begin(); itr != test.end(); itr++)
    //     cout << (*itr) << endl;
    system("pause");
    return 0;
}