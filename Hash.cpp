#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
string Hash(string inp, bool isBinary);

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        cout << "Error: no args. Try (-t \"ExampleFile.txt\") or (-m \"your text\") " << endl;
        system("pause");
        return 0;
    }

    string FileLoc;
    string inp;
    bool isFromText = true;
    bool isBinary = false;
    for (int i = 1; i < argc; i++)
    {
        //cout << argv[i]<<endl;

        if (argv[i][0] == '-' && argv[i][1] == 't')
        {
            if (i + 1 < argc)
            {
                FileLoc = argv[i + 1];
            }
            else
            {
                cout << "Error: no input arg." << endl;
                system("pause");
                return 0;
            }
        }
        else if (argv[i][0] == '-' && argv[i][1] == 'm')
        {
            if (i + 1 < argc)
            {
                inp = argv[i + 1];
                isFromText = false;
            }
            else
            {
                cout << "Error: no input arg." << endl;
                system("pause");
                return 0;
            }
        }

        if (argv[i][0] == '-' && argv[i][1] == 'b')
        {
            isBinary=true;
        }
    }

    if (isFromText)
    {
        ifstream GetTxt(FileLoc);
        if (!GetTxt.is_open())
        {
            cout << "Error: couldn't open file." << endl;
            system("pause");
            return 0;
        }

        stringstream strStream;
        strStream << GetTxt.rdbuf(); //read the file
        string inp = strStream.str();

        cout << Hash(inp,isBinary) << endl;
    }
    else
    {
        cout << Hash(inp,isBinary) << endl;
    }

    system("pause");
    return 0;
}

string Hash(string inp, bool isBinary)
{
    char hash[64] = {(char)0};
    for (int a = 0; a < inp.length(); a++)
    {
        for (int i = 0; i < 64; i++)
        {
            switch (((int)inp[a] + i + a) % 15)
            {
            case 0:
                hash[i] ^= inp[a];
                break;
            case 1:
                hash[i] ^= (inp[a] >> 2);
                break;
            case 2:
                hash[i] ^= (inp[a] >> 1);
                break;
            case 3:
                hash[i] ^= (inp[a] << 2);
                break;
            case 4:
                hash[i] ^= (inp[a] << 1);
                break;
            case 5:
                hash[i] ^= (~inp[a]);
                break;
            case 6:
                hash[i] ^= (~inp[a] << 1);
                break;
            case 7:
                hash[i] ^= (~inp[a] >> 1);
                break;
            case 8:
                hash[i] ^= (~inp[a] >> 2);
                break;
            case 9:
                hash[i] ^= (~inp[a] >> 3);
                break;
            case 10:
                hash[i] ^= (~inp[a] << 2);
                break;
            case 11:
                hash[i] ^= (~inp[a] << 3);
                break;
            case 12:
                hash[i] ^= (~inp[a] >> 1 << 1);
                break;
            case 13:
                hash[i] ^= (~inp[a] >> 2 << 2);
                break;
            case 14:
                hash[i] ^= (~inp[a] >> 3 << 3);
                break;
            }
        }
    }

    string out = "";
    if (isBinary)
    {
        for (int i = 0; i < 64; i++) // convert to hex
        {
            int t = ((int)hash[i]) / 16 + 8;
            cout << (t&1) << endl;
            if((t&8)>0)
            {
                out += '1';
            }
            else
            {
                out += '0';
            }
            if((t&4)>0)
            {
                out += '1';
            }
            else
            {
                out += '0';
            }
            if((t&2)>0)
            {
                out += '1';
            }
            else
            {
                out += '0';
            }
            if((t&1)>0)
            {
                out += '1';
            }
            else
            {
                out += '0';
            }
        }

    }
    else
    {

        for (int i = 0; i < 64; i++) // convert to hex
        {
            int t = ((int)hash[i]) / 16 + 8;

            if (t < 10)
                out += (char)(t + 48);
            else
            {
                switch (t)
                {
                case 10:
                    out += 'a';
                    break;
                case 11:
                    out += 'b';
                    break;
                case 12:
                    out += 'c';
                    break;
                case 13:
                    out += 'd';
                    break;
                case 14:
                    out += 'e';
                    break;
                case 15:
                    out += 'f';
                    break;
                }
            }
        }
    }
    return out;
}