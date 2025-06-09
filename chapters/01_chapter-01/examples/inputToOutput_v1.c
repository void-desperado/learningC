//copy input to output one character at a time version 1
#include <stdio.h>
int main(){
    int ch;
    ch=getchar();
    while(ch!=EOF){
        putchar(ch);
        ch=getchar();
    }
}