//---------------------------------------------------------------------------


#pragma hdrstop

#include "Calculator.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

//---------------------------------------------------------------------------
Calculator::Calculator()
{
    x=0;
    y=0;
}
//---------------------------------------------------------------------------
Calculator::~Calculator()
{
}
//---------------------------------------------------------------------------

float Calculator::Adder(float x,float y)
{
    float He =0;
    He = x+y;
    return He;
}
//---------------------------------------------------------------------------
float Calculator::Substration(float x,float y)
{
    float Cha =0;
    Cha = x-y;
    return Cha;
}
//---------------------------------------------------------------------------
float Calculator::Multiplication(float x,float y)
{
    float Ji =0;
    Ji = x*y;
    return Ji;
}
//---------------------------------------------------------------------------
float Calculator::Division(float x,float y)
{
    float Shang =0;
    if(Y ==0)
        return -1;
    Shang = x/y;
    return Shang;
}
//---------------------------------------------------------------------------
float Calculator::CPow(float x,float y)
{
    float ChengFang =0;
    ChengFang = pow(x,y);
    return ChengFang;
}
//---------------------------------------------------------------------------
float Calculator::CSqrt(float x)
{
    float sqrtC =0;
    sqrtC = sqrt(x);
    return sqrtC;
}
//---------------------------------------------------------------------------




//Main()
void main()
{
    float x=0;
    float y=0;
    cout<<"叫近x:";
    cin>>x;
    cout<<"叫近y:"
    cin>>y;
    cout<<endl;
    Calculator my;
    float He = my.Adder(x,y);
    cout<<"ㄢ计ぇ㎝"<<He<<endl;
    float Cha = my.Substration(x,y);
    cout<<"ㄢ计ぇ畉"<<Cha<<endl;
    float Ji = my.Multiplication(x,y);
    cout<<"ㄢ计ぇ縩"<<Ji<<endl;
    float Shang = my.Division(x,y);
    cout<<"ㄢ计ぇ坝"<<Shang<<endl;
    float Pow = my.Pow(x,y);
    cout<<"xyΩよ:"<<Pow<<endl;
    float KaiFang = my.CSqrt(x);
    cout<<"xキよ"<<KaiFang<<endl;

    cout<<"ヴ種龄祘癶"<<endl;
    getchar();
}
//---------------------------------------------------------------------------
