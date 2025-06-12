//write a function trim to remove blanks, tabs or newlines from the end of a string
#include <stdio.h>
void trim(char string[]){
    int length=0,i;
    for(length=0;string[length]!='\0';length++)
        ;
    for(i=length-1;i>=0;i--){
        if(string[i]!=' ' && string[i]!='\t' && string[i]!='\n')
            break;
    }
    string[i+1]='\0';
}
