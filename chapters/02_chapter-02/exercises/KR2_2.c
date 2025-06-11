//write a loop equivalent to for(i=0;i<lim-1 && (c=getchar())!='\n && c!=EOF;i++) without using && or ||
#include <stdio.h>
int main(){
    int lim,c,i;
    for(i=0;(c=getchar())!='\n';i++){
        if(i<lim-1){
            if(c!=EOF){
            }
            else{
                goto out;
            }
        }
        else{
            goto out;
        }
    }
    out:
}