#include<fstream>
using namespace std;
int main()
{
    ifstream inp ("randomText.txt");
    ofstream out ("randomText2.txt");
    while(!inp.eof())
    {
        string line;
        getline(inp,line);
        out << line << endl;

        if(line[5]=='0')line[5]='1';
        else line[5]='0';
        out << line << endl;
    }
    inp.close();
    out.close();

    return 0;
}