//---------------------------------------------------------------------------

#pragma hdrstop

#include <iostream>
#include <set>
#include <algorithm>
//---------------------------------------------------------------------------
using namespace std;
//---------------------------------------------------------------------------

#pragma argsused
//---------------------------------------------------------------------------
template <class T>
void OutPut(T& s)
{
    T::iterator it;
    for(it=s.begin(); it!=s.end(); it++){
        cout<<" "<<*it<<",";
    }
    cout<<endl;
}
//---------------------------------------------------------------------------
/*void OutPut(set<int>& s)
{
    set<int>::iterator it;
    for(it=s.begin(); it!=s.end(); it++){
        cout<<" "<<*it<<",";
    }
    cout<<endl;
}
//---------------------------------------------------------------------------
void OutPutM(multiset<int>& s)
{
    multiset<int>::iterator it;
    for(it=s.begin(); it!=s.end(); it++){
        cout<<" "<<*it<<",";
    }
    cout<<endl;
}    */
void Print(int& Ele)
{
    cout<<Ele<<",";
}
//---------------------------------------------------------------------------
int main(int argc, char* argv[])
{ /*
    set<int> s1;
    s1.insert(10);
    s1.insert(15);
    s1.insert(20);
    s1.insert(25);
    s1.insert(30);
    s1.insert(33);
    s1.insert(4);
    s1.insert(50);
    s1.insert(11);
    s1.insert(32);

    OutPut(s1);

   set<int> s2;

//   s2.insert(13);
//   s2.insert(11);
//   s2.insert(19);
//   s2.insert(17);
//   s2.insert(17);
//   s2.insert(4);
//    OutPut(s2);   
  

    set<int>::allocator_type s1_Alloc;
    s1_Alloc = s1.get_allocator();
    set<int> s3 (less<int>(), s1_Alloc);
    s3.insert(1);
    s3.insert(5);
    s3.insert(2);
    OutPut(s3);

    set<int> s4(s1);
    OutPut(s4);

    multiset<int> sm1;
    sm1.insert(10);
    sm1.insert(15);
    sm1.insert(25);
    sm1.insert(20);
    sm1.insert(30);
    sm1.insert(33);
    sm1.insert(5);
    sm1.insert(20);
    OutPut(sm1);
        */


    typedef set<int> SET;
    typedef multiset<int> MSET;
    SET s10;
    MSET s11;
    SET::iterator it;
    MSET::iterator Mit;
    pair<SET::iterator, SET::iterator> p1;
    pair<MSET::iterator, MSET::iterator> Mp1;
    s10.insert(10);
    s10.insert(15);
    s10.insert(21);
    s10.insert(17);
    s11.insert(11);
    s11.insert(16);
    s11.insert(20);
    s11.insert(18);
    s11.insert(20);
    cout<<"The Set S1 is below:"<<endl;
    for_each(s10.begin(),s10.end(),Print);
    cout<<endl;

    cout<<"The Set S11 is below:"<<endl;
    for_each(s11.begin(),s11.end(),Print);
    cout<<endl;

    int size=s10.size();
    int Msize = s11.size();
    cout<<"The size of the set s10:"<<size<<endl;
    cout<<"The size of the set s11:"<<Msize<<endl;


    getchar();
    return 0;
}
//---------------------------------------------------------------------------
 