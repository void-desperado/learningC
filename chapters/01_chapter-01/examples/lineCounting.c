//count the number of lines in input
#include <stdio.h>
int main(){
    int ch,count=0;
    while ((ch=getchar())!=EOF)
        if(ch=='\n')
            count++;
    printf("No of lines in input: %d",count);
}