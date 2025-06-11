//contactenate one string at the end of other
#include <stdio.h>
void stringConcatenate(char to[],char from[]){
    int i=0,j=0;
    while(to[i]!='\0')
        i++;
    while((to[i++]=from[j++])!='\0');
}
int main(){
    char str1[100];
    str1[0]='h';
    str1[1]='e';
    str1[2]='l';
    str1[3]='l';
    str1[4]='o';
    str1[5]='\0';
    char str2[]=" world";
    stringConcatenate(str1,str2);
    printf("%s",str1);
}