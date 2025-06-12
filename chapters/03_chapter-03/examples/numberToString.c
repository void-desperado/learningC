//write a function to convert a number to character string
#include <stdio.h>
void itoa(int number,char string[]){
    int reversedNumber=0,tempNumber,i=0;
    if(number<0)
        tempNumber=number*(-1);
    else
        tempNumber=number;    
    while(tempNumber!=0){
        reversedNumber = reversedNumber*10 + tempNumber%10;
        tempNumber/=10;
    }
    tempNumber=reversedNumber;
    if(number<0)
        string[i++]='-';
    while(tempNumber!=0){
        string[i++]=(tempNumber%10)+'0';
        tempNumber/=10;
    }
    string[i]='\0';
}

int main(){
    char array[10];
    itoa(123,array);
    printf("%s",array);
}