//write a function that deletes any character in string 1 which makes any character of string 2
#include <stdio.h>
void squeeze(char string1[],char string2[]){
    int oldStringIndex=0,j=0,presentInStringOrNot,present=1,notPresent=0,newStringIndex=0;
    while(string1[oldStringIndex]!='\0'){
        presentInStringOrNot=notPresent;
        for(j=0;string2[j]!='\0';j++){
            if(string1[oldStringIndex]==string2[j]){
                presentInStringOrNot=present;
                break;
            }
        }
        if(presentInStringOrNot==notPresent)
            string1[newStringIndex++]=string1[oldStringIndex++];
        else if(presentInStringOrNot==present)
            oldStringIndex++;
    }
    string1[newStringIndex]='\0';
}

int main(){
    char str1[]="hello world how are you doing afterall";
    char str2[]="he";
    squeeze(str1,str2);
    printf("%s",str1);
}