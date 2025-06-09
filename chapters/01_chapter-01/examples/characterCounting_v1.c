//count the number of characters in input
#include <stdio.h>
int main(){
    int ch,count=0;
    while ((ch=getchar())!=EOF)
        count++;
    printf("No of characters in input: %d",count);
}