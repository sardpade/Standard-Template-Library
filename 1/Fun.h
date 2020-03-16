#define pi 3.1415926

double area(float Radius)
double area(float Radius)
{
    double A=0;
    A= pi*Radius*Radius;
    return A;
}



//-----------------------------------------------------------
#include <iostream>
#include <cmath>
using namespace std;
double pow2(float x);
double pow3(float* y);

double pow2(float x)
{
    double z=0;
    z= x*x;
    return;
}

double pow3(float* y)
{
    double z=0;
    z= (*y)*(*y)*(*y);
    return;
}

void main()
{
    double A = 10;
    float B= 20;
    double C = 0;
    double D = 0;
    C = pow2(A);
    cout<<""<< A<<""<<C<<endl;
    D = pow3(&B);
    cout<<""<< B<<""<<D<<endl;
    cin.get();


}



//-----------------------------------------------------------


#include <iostream>
using namespace std;
int Factor(int n)
{
    int answer=0;
    if(n==1)
        return 1;
    answer = Factor(n-1)*n;
    return answer;
}

void main()
{
    int n=5;
    int result=0;
    result= Factor(n);
    cout<<""<<result<<endl;
    cin.get();
}



//-----------------------------------------------------------
#include <iostream>
#include <cstring>
#include <string>
using namespace std;
extern int A;
extern int B;

void main()
{
    auto int x=0;
    register int y=0;
    static int count=0;
    char* ch = new char();
    sprintf(ch,"%d,%d,%d,%d,%d", x,y, count, A,B);
    cout<<ch<<endl;
}
