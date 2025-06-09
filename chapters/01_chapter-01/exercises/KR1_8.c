//count the number of lines, blanks and tabs in input
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int main(){
    int ch,lineCount=0,blankCount=0,tabCount=0;
    while ((ch=getchar())!=EOF)
        if(ch=='\n')
            lineCount++;
        else if(ch=='\t')
            tabCount++;
        else if(isspace(ch))
            blankCount++;
    printf("No of lines in input: %d\nNo of tabs in input: %d\nNo of blanks in input: %d",lineCount,tabCount,blankCount);
}