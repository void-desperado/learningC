//copy input to output replacing any no of blanks with a single blank
#include <stdio.h>
#include <ctype.h>

int main(){
    int ch,buffer;
    while((ch=getchar())!=EOF){
        if((ch=='\t')||(ch==' ')||(ch=='\f')||(ch=='\v')||(ch=='\r')){
            while((ch=='\t')||(ch==' ')||(ch=='\f')||(ch=='\v')||(ch=='\r')){
                ch=getchar();
            }
            putchar(' ');
        }
        putchar(ch);
    }
}