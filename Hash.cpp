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

    for(int a=0;a<inp.length();a++)
    {
        for(int i =0;i<64;i++)
        {
            switch (((int)inp[a]+i)%15)
            {
                case 0:
                    hash[i] ^= inp[i%inp.length()];
                    break;
                case 1:
                    hash[i] ^= (inp[i%inp.length()]>>2);
                    break;
                case 2:
                    hash[i] ^= (inp[i%inp.length()]>>1);
                    break;
                case 3:
                    hash[i] ^= (inp[i%inp.length()]<<2);
                    break;
                case 4:
                    hash[i] ^= (inp[i%inp.length()]<<1);
                    break;
                case 5:
                    hash[i] ^= (~inp[i%inp.length()]);
                    break;
                case 6:
                    hash[i] ^= (~inp[i%inp.length()]<<1);
                    break;
                case 7:
                    hash[i] ^= (~inp[i%inp.length()]>>1);
                    break;
                case 8:
                    hash[i] ^= (~inp[i%inp.length()]>>2);
                    break;
                case 9:
                    hash[i] ^= (~inp[i%inp.length()]>>3);
                    break;
                case 10:
                    hash[i] ^= (~inp[i%inp.length()]<<2);
                    break;
                case 11:
                    hash[i] ^= (~inp[i%inp.length()]<<3);
                    break;
                case 12:
                    hash[i] ^= (~inp[i%inp.length()]>>1<<1);
                    break;
                case 13:
                    hash[i] ^= (~inp[i%inp.length()]>>2<<2);
                    break;
                case 14:
                    hash[i] ^= (~inp[i%inp.length()]>>3<<3);
                    break;
     
            }
        }
    }

    cout << "Hash: \n";
    for(int i =0;i<64;i++)
    {
        cout << hex<< ((int)hash[i]/16+8);
    }
    cout << endl<<endl;

    system("pause");
    return 0;
}