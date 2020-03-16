//聲明

int a;
float b;
struct s{
    int a;
    float b;

};
extern int x;
void count(bool YN,int& counter);




//定義
void count(bool YN, int& counter)
{
    if(YN)
        counter++;
}




//main
void main()
{
    int counter =0;
    bool YN = 1;
    while(YN)
    {
        count(YN,counter);
        cout<<counter<<endl;
        if(coutner>5)
            YN=0;

    }

}


double pi = 3.1415926;
char* ch = "Here";

typedef int INT32;
typedef short INT_16;
typedef unsigned char UCHAR;

