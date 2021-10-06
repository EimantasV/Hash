#include<fstream>
using namespace std;
int main()
{
    string line;
    ofstream out ("randomText3.txt");
    line = "a                         ";
    for(int i =0;i<1000000;i++)
    {
        out << line << endl;
        line[0]++;
        for(int a=0;a<20;a++)
        {
            if(line[a]=='{')
            {
                line[a]='a';

                if(line[a+1]==' ') 
                    line[a+1] ='a';
                else
                    line[a+1]+=1;
            }
        }
    }

    out.close();

    return 0;
}