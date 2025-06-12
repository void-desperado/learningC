//convert string to integer coping with any leading space and sign
#include <stdio.h>
int atoi(char string[]){
    int i=0,positive=1,negative=-1,sign=positive,result=0;
    while(string[i]!='\0'){
        if(string[i]==' ' || string[i]=='+' || string[i]=='-' || (string[i]>='0' && string[i]<='9'))
            i++;
        else    
            return -1;
    }
    i=0;
    while(string[i]==' '){
        i++;
    }
    if(string[i]=='-'){
        sign=negative;
        i++;
    }
    else if(string[i]=='+'){
        sign=positive;
        i++;
    }
    else{
        sign=positive;
    }
    while(string[i]!='\0'){
        result=(result*10) + (string[i]-'0');
        i++;
    }
    return sign*result;
}

int main(){
    printf("%d",atoi("  +1234"));
}