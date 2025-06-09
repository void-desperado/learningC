//copy input to output one character at a time version 2
#include <stdio.h>
int main(){
    int ch;
    while((ch=getchar())!=EOF)
        putchar(ch);
}