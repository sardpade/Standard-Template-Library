//---------------------------------------------------------------------------

#pragma hdrstop
#include <iostream>
#include <stack>
#include <string>
#include <list>
#include <assert.h>

using namespace std;
//---------------------------------------------------------------------------

#pragma argsused
int main(int argc, char* argv[])
{
    stack<string,list<string> > s1;
    s1.push("Haidian district");
    s1.push("char");
    s1.push("xuan");
    s1.push("xich");
    assert(s1.size() == 4);
    while(s1.size()){
        cout<< "  "<<s1.top()<<endl;
        s1.pop();
    }
    getchar();
    return 0;
}
//---------------------------------------------------------------------------
 