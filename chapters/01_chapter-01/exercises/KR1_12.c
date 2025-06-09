#include <stdio.h>
#include <ctype.h>
int main(){
    int ch, in=1, out=0,word;
    word=out;
    while((ch=getchar())!=EOF){
        if(!isspace(ch)){
            word=in;
            putchar(ch);
        }
        else if(isspace(ch)){
            if(word==in){
                word=out;
                putchar('\n');
            }
        }
    } 
}