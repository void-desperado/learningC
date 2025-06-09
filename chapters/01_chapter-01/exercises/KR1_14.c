//print a horizontal histogram of the frequencies of different characters in input
#include <stdio.h>
int main(){
    int ch,characterCount[256],noOfCharacters=0,max=0;
    for(int i=0;i<256;i++){
        characterCount[i]=0;
    }

    while((ch=getchar())!=EOF){
        characterCount[ch]++;
    }

    for(int i=0;i<256;i++){
        if (characterCount[i]!=0){
            printf("%3d",i);
            printf("|");
            for(int j=0;j<characterCount[i];j++){
                printf("-");
            }
            printf("\n");
        }
    }
    for(int i=0;i<20;i++){
        printf("---");
    }
}