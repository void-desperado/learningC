//print a vertical histogram for the length of words in input
#include <stdio.h>
#include <ctype.h>
int main(){
    int ch, wordCount=0, in=1, out=0,word,wordlengths[100],i=0,j,max=0;
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
    for(j=0;j<wordCount;j++){
        if(wordlengths[j]>=max)
            max=wordlengths[j];
    }
    printf("%d\n",max);

    for(j=0;j<wordCount;j++){
        wordlengths[j]=max-wordlengths[j];
    }

    printf("|\n|\n|\n");
    for(j=0;j<max;j++){
        printf("|");
        for(int k=0;k<wordCount;k++){
            if(wordlengths[k]==0){
                printf(" | ");
            }
            else if(wordlengths[k]!=0){
                printf("   ");
                wordlengths[k]--;
            }
        }
        printf("\n");
    }
    for(int k=0;k<wordCount;k++){
        printf("___");
    }
}