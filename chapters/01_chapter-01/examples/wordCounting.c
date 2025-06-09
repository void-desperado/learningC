//count the number of lines, words and characters in input
#include <stdio.h>
#include <ctype.h>
int main(){
    int ch, wordCount=0, characterCount=0, lineCount=0, in=1, out=0,word;
    word=out;
    while((ch=getchar())!=EOF){
        characterCount++;
        if(ch=='\n')
            lineCount++;
        if(!isspace(ch)){
            word=in;
        }
        else if(isspace(ch)){
            if(word==in){
                word=out;
                wordCount++;
            }
        }
    } 
    printf("No of characters: %d\nNo of words: %d\nNo of lines: %d",characterCount,wordCount,lineCount);
}