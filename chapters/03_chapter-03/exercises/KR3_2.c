//write a function escape(s,t) that converts characters like tab and newline into visible escape sequences
#include <stdio.h>
void escape(char to[],char from[]){
    int i=0;
    while(from[i]!='\0'){
        if(from[i]=='\n')
            to[i]='n';
        else if(from[i]=='\t')
            to[i]='t';
        else    
            to[i]=from[i];
        i++;
    }
    to[i+1]='\0';
}

int main(){
    char array[1000],newArray[1000];
    int ch,i=0;
    while((ch=getchar())!=EOF){
        array[i++]=ch;
    }
    array[i]='\0';
    escape(newArray,array);
    i=0;
    while(newArray[i]!='\0'){
        if(newArray[i]=='n')
            printf("\\n");
        else if(newArray[i]=='t')
            printf("\\t");
        else
            printf("%c",newArray[i]);
        i++;
    }
}