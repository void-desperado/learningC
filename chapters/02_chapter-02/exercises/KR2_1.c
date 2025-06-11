//calculate the range of signed and unsigned char, short, int and long
#include <stdio.h>
#include <limits.h>
int main(){
    printf("Unsigned char: 0 to %d\n",UCHAR_MAX);
    printf("Signed char: %d to %d\n",SCHAR_MIN,SCHAR_MAX);
    printf("Unsigned short: 0 to %d\n",USHRT_MAX);
    printf("Signed short: %d to %d\n",SHRT_MIN,SHRT_MAX);
    printf("Unsigned int: 0 to %d\n",UINT_MAX);
    printf("Signed int: %d to %d\n",INT_MIN,INT_MAX);
    printf("Unsigned long: 0 to %d\n",ULONG_MAX);
    printf("Signed long: %d to %d\n",LONG_MIN,LONG_MAX);
}