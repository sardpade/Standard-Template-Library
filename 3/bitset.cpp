//---------------------------------------------------------------------------

#pragma hdrstop

#include <iostream>
#include <bitset>
#include <string>
using namespace std;
//---------------------------------------------------------------------------

void print(bitset<16>& b)
{
    int i =0;
    int bsize = b.size();
    for(int i=0;i<bsize;i++){
        cout<<b[i];
    }
    cout<<"  :"<<"The size of bitset:"<<bsize<<endl;
}
//---------------------------------------------------------------------------

#pragma argsused
int main(int argc, char* argv[])
{
    string str = "0011111111111111110000";
    bitset<16> b1;
    bitset<16> b2(25);
    bitset<16> b3(str,2,16);
    print(b1);
    print(b2);
    print(b3);
    getchar();
    return 0;
}
//---------------------------------------------------------------------------
