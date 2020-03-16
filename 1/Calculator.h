#include <iostream>
#include <cmath>
#include <stdio.h>
using namespace std;

class Calculator
{
public:
    Calculator();
    ~Calculator();
    float x;
    float y;
    float Adder(float x,float y);
    float Substration(float x,float y);
    float Multiplication(float x,float y);
    float Division(float x,float y);
    float CPow(float x,float y);
    float CSqrt(float x);
};
