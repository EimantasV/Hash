#include <iostream>
#include <fstream>
#include <sstream>
#include "Hash.cpp"
using namespace std;

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
        GetTxt.close();
    }
    else
    {
        cout << Hash(inp,isBinary) << endl;
    }

    system("pause");
    return 0;
}