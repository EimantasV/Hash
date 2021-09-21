#include<fstream>
using namespace std;
int main()
{
    ifstream inp ("randomText.txt");
    ofstream out ("randomText2.txt");
    int n=0;
    string chars = "abcdefghijklmnoprstuvzABCDEFGHIJKLMNOPRSTUVZ1234567890";
    while(!inp.eof())
    {
        string line;
        getline(inp,line);
        out << line << endl;

        if(line[5]==chars[n%55])line[5]=chars[(n+1)%55];
        else line[5]=chars[n%55];
        out << line << endl;
        n++;
    }
    inp.close();
    out.close();

    return 0;
}