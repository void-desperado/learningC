//count the no of each digit, whitespace or newline or tab and all other characters
#include <stdio.h>
int main(){
    int ch,digitsCount[10]={0,0,0,0,0,0,0,0,0,0},spaceCount=0,otherCharactersCount=0;
    while((ch=getchar())!=EOF){
        switch (ch){
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7': 
            case '8':
            case '9':
                digitsCount[ch-'0']++;
                break;
            case ' ':
            case '\n':
            case '\t':
                spaceCount++;
                break;
            default:
                otherCharactersCount++;
        }
    }
    printf("Digits: \n");
    for(int i=0;i<10;i++){
        printf("%d- %d\n",i,digitsCount[i]);
    }
    printf("Whitespace count: %d\nOther characters count: %d",spaceCount,otherCharactersCount);
}