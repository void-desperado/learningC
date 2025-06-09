//count the number of each digits, blanks, tabs, newlines and all other characters
#include <stdio.h>
int main(){
    int ch, digitsCount[10], blankCount=0, tabCount=0, newlineCount=0, otherCharacterCount=0;
    for(int i=0;i<10;i++){
        digitsCount[i]=0;
    } 
    while((ch=getchar())!=EOF){
        if(ch=='\n')
            newlineCount++;
        else if(ch=='\t')
            tabCount++;
        else if(ch==' ')
            blankCount++;
        else if((ch>='0')&&(ch<='9'))
            digitsCount[ch-'0']++;
        else    
            otherCharacterCount++;
    }
    printf("Digits count: \n");
    for(int i=0;i<10;i++){
        printf("%d: %d\n",i,digitsCount[i]);
    }
    printf("No of blanks: %d\nNo of tabs: %d\nNo of newlines: %d\nNo of other characters: %d",blankCount,tabCount,newlineCount,otherCharacterCount);

}