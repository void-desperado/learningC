//convert a string to lower case
void lowerCase(char string[]){
    int i=0;
    while(string[i]!='\0'){
        if(string[i]>='A' && string[i]<='Z'){
            string[i]=string[i]+32;
        }
        i++;
    }
}