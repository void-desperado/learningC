//convert hexadecimal to integer value
#include <stdio.h>
int raisedToPower(int base,int power){
    int result=1;
    for(int i=0;i<power;i++){
        result = result*base;
    }
    return result;
}

int checkIfValid(char hexadecimalString[]){
    int i=0,valid=1;
    while(hexadecimalString[i]!='\0'){
        if ((hexadecimalString[i]>='0' && hexadecimalString[i]<='9')||(hexadecimalString[i]>='a' && hexadecimalString[i]<='f')||(hexadecimalString[i]>='A' && hexadecimalString[i]<='F'))
            valid=1;
        else{
            valid=0;
            break;
        }
        i++;
    }
    if (valid==1)
        return 1;
    else if (valid==0)
        return 0;
}

int hexadecimalToInteger(char hexadecimalString[]){
    int i=0,lenghtOfHexa=0;
    int result=0;
    char newHexadecimalString[100];
    for(int k=0;k<100;k++){
        newHexadecimalString[k]=0;
    }
    if (hexadecimalString[0]=='0' && (hexadecimalString[1]=='x' || hexadecimalString[1]=='X')){
        while(hexadecimalString[i+2]!='\0'){
            newHexadecimalString[i]=hexadecimalString[i+2];
            i++;
        }
        newHexadecimalString[i]='\0';
    }
    else{
        while(hexadecimalString[i]!='\0'){
            newHexadecimalString[i]=hexadecimalString[i];
            i++;
        }
    }
    if(!checkIfValid(newHexadecimalString)){
        return 0;
    }
    i=0;
    while(newHexadecimalString[i]!='\0'){
        lenghtOfHexa+=1;
        i++;
    }
    lenghtOfHexa-=1;
    i=0;
    while(newHexadecimalString[i]!='\0'){
        if(newHexadecimalString[i]>='0' && newHexadecimalString[i]<='9'){
            result = result + ((newHexadecimalString[i]-'0')*raisedToPower(16,lenghtOfHexa--));
        }
        else if(newHexadecimalString[i]>='a' && newHexadecimalString[i]<='f'){
            result = result + ((newHexadecimalString[i]-'a'+10)*raisedToPower(16,lenghtOfHexa--));
        }
        else if(newHexadecimalString[i]>='A' && newHexadecimalString[i]<='F'){
            result = result + ((newHexadecimalString[i]-'A'+10)*raisedToPower(16,lenghtOfHexa--));
        }
        i++;
    }
    return result;
}

int main(){
    printf("%d",hexadecimalToInteger("0XABC43"));
}