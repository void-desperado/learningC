//write a function squeeze to remove all occurences of a particular character from string
#include <stdio.h>
void squeeze(char string[],char ch){
    int i=0,j=0;
    char newString[100];
    while(string[i]!='\0'){
        if(string[i]!=ch){
            newString[j++]=string[i++];
        }
        else{
            string[i++];
        }
    }
    newString[j]='\0';
    i=0;
    while(newString[i]!='\0'){
        string[i]=newString[i];
        i++;
    }
    string[i]='\0';
}
void squeeze2(char string[],char ch){
    int i=0,j=0;
    char newString[100];
    while(string[i]!='\0'){
        if(string[i]==ch){
            i++;
        }
        else{
            string[j++]=string[i++];
        }
    }
    string[j]='\0';
}
int main(){
    char string[]="hello world how are you doing";
    squeeze(string,'o');
    printf("%s\n",string);

    char string2[]="hello world how are you doing";
    squeeze2(string2,'o');
    printf("%s\n",string2);
}