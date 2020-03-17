//---------------------------------------------------------------------------

#pragma hdrstop

#pragma warning(disable:4786)

#include <iostream>
#include <deque>
#include <algorithm>
#include <string>
#include <iomanip.h>
#include <function.h>
//---------------------------------------------------------------------------
using namespace std;
//---------------------------------------------------------------------------
#pragma argsused
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
void Out(double& Ele)
{
    cout.width(5);
    cout.precision(1);
    cout<<std::fixed<<Ele<<",";
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
int main(int argc, char* argv[])
{
    deque<double>::iterator Iter;
    deque<double>::reverse_iterator rIter;
    deque<double> D1,D2,D3;
    for(int i=0;i<10;i++){
        D1.push_front(90+i/10.0);
    }

    cout<<"All the elements of ÂùºÝ§Ç¦CD1:"<<endl;
    for_each(D1.begin(),D1.end(),Out);
    cout<<endl;

    Iter = D1.begin();
    double begin = *Iter;
    Iter = D1.end();
    double end = *(--Iter);
    

    cin.get();
    return 0;
}
//---------------------------------------------------------------------------

