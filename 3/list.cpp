//---------------------------------------------------------------------------

#pragma hdrstop

#pragma warning(disable:4786)

#include <iostream>
#include <list>
#include <algorithm>
#include <string>
#include <iomanip.h>
#include <function.h>
//---------------------------------------------------------------------------
using namespace std;
//---------------------------------------------------------------------------
#pragma argsused
//---------------------------------------------------------------------------
template<class T> void print(const T& Ele)
{
    cout<<" "<<Ele<<";"<<endl;
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
void Print_D(double& Ele)
{
    cout.width(5);
    cout.precision(1);
    cout<<std::fixed<<Ele<<",";
}
//---------------------------------------------------------------------------
void Print_I(int& Ele)
{
    cout<<Ele<<",    ";
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
template<typename A> void print(list<A>& mylist_A)
{
    list<A>::iterator iter;       
    mylist_A.reverse();
    for(iter=mylist_A.begin();iter!= mylist_A.end();iter++)
    {
        cout<<*iter<<",  ";
    }
    cout<<endl;
}
//---------------------------------------------------------------------------
int main(int argc, char* argv[])
{
    list<string> mylist_string;
    list<double> mylist_double;

    mylist_string.push_front("1.   jack");
    mylist_string.push_front("2.   Tom");
    mylist_string.push_front("3.   Mike");

    mylist_double.push_front(10.0);
    mylist_double.push_front(20.0);
    mylist_double.push_front(30.0);
    mylist_double.push_front(40.0);
    mylist_double.push_front(50.0);

    list<int> mylist_int(6,0);
    list<double> mylist_double2(6,0.0);
    list<int> elselist(mylist_int);
    list<double> Iterlist( mylist_double.begin(),mylist_double.end());

    cout<<" the strig list: mylist_string is below:" <<endl;
    list<string>::iterator iter_string;
    for(iter_string = mylist_string.begin(); iter_string !=mylist_string.end(); iter_string++){
        print(*iter_string);
    }

    cout<<" the double list: mylist_double is below:" <<endl;
    for_each(mylist_double.begin(),mylist_double.end(),Print_D);
    cout<<endl;

    cout<<" the double list: mylist_double2 is below:" <<endl;
    for_each(mylist_double2.begin(),mylist_double2.end(),Print_D);
    cout<<endl;

    cout<<" the double list: Iterlist is below:" <<endl;
    for_each(Iterlist.begin(),Iterlist.end(),Print_D);
    cout<<endl;

    cout<<" the double list: mylist_int is below:" <<endl;
    for_each(mylist_int.begin(),mylist_int.end(),Print_I);
    cout<<endl;

    cout<<" the double list: elselist is below:" <<endl;
    for_each(elselist.begin(),elselist.end(),Print_I);
    cout<<endl;




    //----------------------------T-------------------
    list<double> list_One,list_Two,list_Three;
    double Ele = 0.0;
    for(int i=0;i<10;i++){
        Ele = i+i/10.0;
        list_One.push_front(Ele);
    }
    cout<<" list_One:   ";
    print(list_One);
    list_Two.assign(5,5.6);
    print(list_Two);
    list_Three.assign(list_One.begin(),list_One.end());
    cout<<" list_Three:   ";
    print(list_Three);


    int a = 10;
    int b = 20;
    swap(a, b);
    cout<<a<<"   "<<b<<endl;

    //-------------------------------------------------------------
    list<int> L1,L2,L3;
    list<int>::iterator I1,I2,I3;
    L1.push_back(1);
    L1.push_back(5);
    L2.push_back(2);
    L2.push_back(3);
    L3.push_back(7);
    L3.push_back(8);

    cout<<" L1:" ;
    for_each(L1.begin(),L1.end(),Print_I);
    cout<<endl;
    cout<<" L2:" ;
    for_each(L2.begin(),L2.end(),Print_I);
    cout<<endl;
    cout<<" L3:" ;
    for_each(L3.begin(),L3.end(),Print_I);
    cout<<endl;

    cout<<" L1 Merges L2 and L3 :" ;
    L1.merge(L2);
    L1.merge(L3);
    for_each(L1.begin(),L1.end(),Print_I);
    cout<<endl;

    L1.sort(greater<int>());
    cout<<" L1:";
    for_each(L1.begin(),L1.end(),Print_I);
    cout<<endl;

    L1.sort();
    cout<<" L1:";
    for_each(L1.begin(),L1.end(),Print_I);
    cout<<endl;

    L1.remove_if(bind2nd(greater<int>(), 3));
    for_each(L1.begin(),L1.end(),Print_I);
    cout<<endl;


    not_equal_to<int>Pred;

    cin.get();
    return 0;
}
//---------------------------------------------------------------------------
