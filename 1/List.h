#include <iostream>
#include <list>
using namespace std;
struct PERSON{
    int id,sex;
    double core;

    void clear()
    {
        id =0;
        sex=0;
        core=0;
    }

};

void main()
{
    PERSON temp;
    list<PERSON> C1;
    int id_temp,sex_temp,size;
    double core_temp;
    C1.clear();

    int counter=0;
    cout<<"This is a simplest C++ Example! \n"<<endl;
    cout<<"任意鍵開始。。。";
    cin.get();
    while(counter<5)
    {
        cout<<;
        cin>>id_temp;
        cout<<;
        cin>>sex_temp;
        cout<<;
        cin>>core_temp;
        temp.id= id_temp;
        temp.sex= sex_temp;
        temp.core= core_temp;
        C1.push_back(temp);
        memset(&temp,0,sizeof(PERSON));
        counter++;
    }

    cout<<"按<enter>鍵繼續"<<endl;
    cin.get();

    size = C1.size();
    cout<<endl;
    list<PERSON>::iterator iter;
    for(iter=C1.begin();iter!=C1.endl();Iter++){
        temp.clear();
        temp = *iter;
        cout<<""<<temp.id<<""<<temp.sex<<""<<temp.core<<endl;
    }

    cout<<"";
    cin.get();
    return;
}
