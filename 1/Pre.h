#define PI 3.1415926

#define PASTE(n) "adhfkj"#n

main()
{
    printf("%s", PASTE(15);
}

adhfkj15



//----------------------------------------------
#include <stdio.h>
#define NUM(a,b,c) a##b##c
#define STR(a,b,c) a##b##c
main()
{
    printf("%d", NUM(1,2,3));
    printf("%s", STR("aa","bb", "cc");
}


//----------------------------------------------

example 1

#define PI 3.1415926
    main()
    {

    }
#undef PI



Example 2

#include "stdio.h"

int main()
{
    #define MAX 200
    printf("Max=%d\n", Max);
    #undef MAX
    #define MAX 150
    printf("Max=%d\n", Max);
    getchar();
    return 0;
}


//-------------------------------------------------------------------------


#define MAX 10

main()
{
    #if Max>99
        printf("1234\n");
    #else
        printf("abcd\n");
    #endif

}
//-------------------------------------------------------------------------
#define DEBUG

main()
{
    #ifdef DEBUG
        printf("1234\n");
    #else
        printf("abcd\n");
    #endif

}
//-------------------------------------------------------------------------
#define DEBUG

main()
{
    #ifdef DEBUG
        printf("1234\n");
    #else
        printf("abcd\n");
    #endif

}
//-------------------------------------------------------------------------
#ifndef _FILENAME_H
    #define _FILENAME_H
#endif
#if _WINDOWS_
    #define OS_VER "WINDOWS"
#else
    #define OS_VER "UNIX"
#endif
//-------------------------------------------------------------------------

//-------------------------------------------------------------------------
#include ""


#if VERSION == 1
    #define INCFILE "vers1.h"
#elif VERSION==2
    #define INCFILE "vers2.h"
#else
    #define INCFILE "versN.h"
#endif

#include INCFILE
