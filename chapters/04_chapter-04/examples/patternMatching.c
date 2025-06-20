#include <stdio.h>
#define MAXLINE 1000

int getline(char line[],int limit);
int strIndex(char source[],char searchFor[]);

char pattern[]="ould";

int getline(char line[],int limit){
    int c,i;

    i=0;
    while(--limit>0 && (c=getchar())!=EOF && c!='\n')
        line[i++]=c;
    if(c=='\n')
        line[i++]=c;
    line[i]='\0';
    return i;
}

int strIndex(char source[],char searchFor[]){
    int i,j,k;

    for(i=0;source[i]!='\0';i++){
        for(j=i,k=0;searchFor[k]!='\0' && source[j]==searchFor[k];j++,k++)
            ;
        if(k>0 && searchFor[k]=='\0')
            return i;
    }
    return -1;
}

int main(){
    char line[MAXLINE];

    while(getline(line,MAXLINE)>0)
        if(strIndex(line,pattern)>=0){
            printf("%s",line);
        }
}