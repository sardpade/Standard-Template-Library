#include <iostream>
#include <string>
using namespace std;

template <typename T>
void print(const T& var)
{
    cout<<var<<endl;
}

void main()
{
    string str("");
    print(str);
    cin.get();
}


//-----------------------------------------------------------
#include <iostream>
#include <string>
using namespace std;

template <typename T>
void print(T& iim, T& jj)
{
    cout<<ii<<endl;
    cout<<jj<<endl;
}

void main()
{
    string strA("");
    string strB("");
    print(strA, strB);
    cin.get();
}
//-----------------------------------------------------------

#include <iostream>
#include <string>
using namespace std;

template <class T1, class T2>
void print(T1& iim, T2& jj)
{
    cout<<ii<<endl;
    cout<<jj<<endl;
}

void main()
{
    string strA("");
    int B = 50;
    print(strA, B);
    cin.get();
}

//-----------------------------------------------------------
#include <iostream>
#include <string>
#include <sstream>

template <class T>
T fromString(const std::string& s)
{
    std::istringstream is(s);
    T t;
    is>>t;
    return t;
}

template <class T>
std::string toString(const T& t)
{
    std::ostringstream s;
    s<<t;
    return s.str();
}

