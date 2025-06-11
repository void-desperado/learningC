//convert a string of digits into its numerical equivalent
int atoi(char stringOfDigits[]){
    int result=0,i=0;
    while(stringOfDigits[i]!='\0'){
        result = (result*10) + (stringOfDigits[i++]-'0');
    }
    return result;
}