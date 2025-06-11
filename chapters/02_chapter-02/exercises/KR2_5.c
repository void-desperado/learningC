//write a function which returns the first location in s1 where any character from s2 occurs
#include <stdio.h>
void any(char string1[],char string2[]){
    int loopCountForString2=0,lengthOfString2,loopCountForString1=0;
    while(string2[loopCountForString2]!='\0'){
        lengthOfString2++;
        loopCountForString2++;
    }
    int locations[lengthOfString2];
    for(int i=0;i<lengthOfString2;i++){
        locations[i]=-1;
    }
    loopCountForString2=0;
    while(string2[loopCountForString2]!='\0'){
        for(loopCountForString1=0;string1[loopCountForString1]!='\0';loopCountForString1++){
            if(string2[loopCountForString2]==string1[loopCountForString1]){
                locations[loopCountForString2]=loopCountForString1+1;
                break;
            }
        }
        loopCountForString2++;
    }
    for(int i=0;string2[i]!='\0';i++){
        printf("%c: %d\n",string2[i],locations[i]);
    }
}

int main(){
    any("Hello world","how are you doing");
}