#include <iostream>
#include <fstream>

using namespace std;
void main()
{
    ifstream f1;
    ifstream f2;
    char filename1[256];
    char filename2[256];
    char content[256];
    cout<<"";
    cin>>filename1;
    cout<<"";
    cin>>filename2;
    f1.open(filename1,ios::in);
    f2.open(filename2,ios::out);
    while(!f1.eof())
    {
        f1.getline(content, 128);
        f2<<coutent<<endl;
    }
    f1.close();
    f2.close();
}
 