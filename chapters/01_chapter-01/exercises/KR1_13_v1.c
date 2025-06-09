//print a horizontal histogram for the length of words in input
#include <stdio.h>
#include <ctype.h>
int main(){
    int ch, wordCount=0, in=1, out=0,word,wordlengths[100],i=0,j;
    word=out;
    for(int i=0;i<100;i++){
        wordlengths[i]=0;
    }
    while((ch=getchar())!=EOF){
        if(!isspace(ch)){
            word=in;
            wordlengths[i]++;
        }
        else if(isspace(ch)){
            if(word==in){
                word=out;
                wordCount++;
                i++;
            }
        }
    } 
    j=0;
    while(wordlengths[j]!=0){
        printf("%d ",wordlengths[j++]);
    } 
    printf("\n"); 
    j=0;
    while(wordlengths[j]!=0){
        printf("%d|",wordlengths[j]);
        for(int k=0;k<wordlengths[j];k++){
            printf("-");
        }
        printf("\n");
        j++;
    }
    printf(" "); 
    for(int i=0;i<20;i++){
        printf("-");
    }
}