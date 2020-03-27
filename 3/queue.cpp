//---------------------------------------------------------------------------

#pragma hdrstop

#include <iostream>
#include <queue>
#include <string>
#include <list>
#include <assert.h>

using namespace std;

//---------------------------------------------------------------------------

#pragma argsused
int main(int argc, char* argv[])
{
    queue<string, list<string> > q1;
    q1.push("s");
    q1.push("b");

    q1.push("c");
    q1.push("d");

    while(q1.size()){
        cout<<"  "<<q1.back()<<endl;
        q1.pop();
    }

    getchar();
    return 0;
}
//---------------------------------------------------------------------------
 