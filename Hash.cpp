#include<iostream>
using namespace std;

int main()
{
    cout << "Input: \n";
    string inp;
    cin >> inp;
    cout << '\n';
    char hash[64]= {(char)0};
    

    //cout << inp.length() << endl;
    if(inp.length() < 64)
    {
        for(int i =0;i<64;i++)
        {
            //cout << (a%inp.length()) << endl;
            hash[i] = inp[i%inp.length()];
        }
    }
    else
    {
        for(int i=0;i<inp.length();i++)
        {
            hash[i%64]^=inp[i];
        }
    }
    // }

    // for(int a=0;a<inp.length();a++)
    // {
    //     if(a<64)
    //     {
    //         cout << (a%inp.length()) << endl;
    //         hash[a] = inp[a%inp.length()];
    //     }
    //     for(int i =0;i<64;i++)
    //     {
    //         //hash[i]^=inp[a];
    //     }
    // }
    cout << "Hash: \n";
    for(int i =0;i<64;i++)
    {
        cout << hash[i];
    }
    cout << endl<<endl;

    system("pause");
    return 0;
}