#include <iostream>
#include <fstream>
#include <sstream>
#include<string>
#include <Windows.h>
#include "HashNew.h"
#include <bitset>

int main(int argc, char *argv[])
{
    //SetConsoleOutputCP(CP_UTF8);
    if (argc == 1)
    {
        std::cout << "Error: no args. Try (-t \"ExampleFile.txt\") or (-m \"your text\") " << std::endl;
        system("pause");
        return 0;
    }
    std::string FileLoc;
    std::string inp;
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
                std::cout << "Error: no input arg." << std::endl;
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
                std::cout << "Error: no input arg." << std::endl;
                system("pause");
                return 0;
            }
        }

        if (argv[i][0] == '-' && argv[i][1] == 'b')
        {
            isBinary=true;
        }
    }

    if(!isFromText && !isBinary)
    {
        std::cout << HashHex(inp)<<std::endl;
    }
    else if(!isFromText && isBinary)
    {
        std::cout << HashBit(inp)<<std::endl;
    }
    else if (isFromText && !isBinary)
    {
        std::ifstream GetTxt(FileLoc);
        if (!GetTxt.is_open())
        {
            std::cout << "Error: couldn't open file." << std::endl;
            system("pause");
            return 0;
        }

        std::stringstream strStream;
        strStream << GetTxt.rdbuf(); //read the file
        std::string inp = strStream.str();

        std::cout << HashHex(inp) << std::endl;
        GetTxt.close();
    }
    else 
    {
        std::ifstream GetTxt(FileLoc);
        if (!GetTxt.is_open())
        {
            std::cout << "Error: couldn't open file." << std::endl;
            system("pause");
            return 0;
        }

        std::stringstream strStream;
        strStream << GetTxt.rdbuf(); //read the file
        std::string inp = strStream.str();

        std::cout << HashBit(inp) << std::endl;
        GetTxt.close();
    }

    

    // std::cout << HashBit("b") <<std::endl<<std::endl;
    // std::cout << HashHex("b") <<std::endl;

    system("pause");
    return 0;
}