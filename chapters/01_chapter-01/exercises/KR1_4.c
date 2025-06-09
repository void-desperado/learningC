//celsius to fahrenheit conversion table using while loop
#include <stdio.h>
int main(){
    int lower=0,upper=300,difference=20,presentTemp;
    presentTemp=lower;
    while(presentTemp<=upper){
        printf("%3d %6.2f\n",presentTemp,(32+((9.00/5.00)*presentTemp)));
        presentTemp+=difference;
    }
}