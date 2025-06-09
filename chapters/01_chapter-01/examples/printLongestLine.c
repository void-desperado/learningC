//read a set of text lines and print the longest
#include <stdio.h>
#define MAXLINESIZE 100
int lineSize(char line[],int limitLength){ //return the length of line
    int length=0,i=0;
    while((line[i]!='\0')&&(length<limitLength)){
        length++;
        i++;
    }
    return length;
}

void copy(char to[],char from[]){ //copies character array from into to
    int i=0;
    while(from[i]!='\0'){
        to[i]=from[i];
        i++;
    }
}

int main(){
    int ch=0,maxSize=0,lineLength=0,i=0;
    char line[MAXLINESIZE],longestLine[MAXLINESIZE];
    for(int i=0;i<MAXLINESIZE;i++){
        line[i]=0;
        longestLine[i]=0;
    }
    do{
        ch=getchar();
        if ((ch=='\n')||(ch==EOF)){
            line[i]='\0';
            i=0;
            lineLength=lineSize(line,MAXLINESIZE);
            if(lineLength>=maxSize){
                copy(longestLine,line);
                maxSize=lineLength;
            }
        }
        else{
            line[i++]=ch;
        }
    }while(ch!=EOF);
    printf("%s",longestLine);
}