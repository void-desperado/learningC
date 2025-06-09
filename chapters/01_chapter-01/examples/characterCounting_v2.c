//count the number of characters in input using for loop
#include <stdio.h>
int main(){
    int count;
    for(count=0;getchar()!=EOF;count++)
        ;
    printf("No of characters in input: %d",count);
}