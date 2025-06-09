//fahrenheit to celsius conversion table using while loop with a heading over the table
#include <stdio.h>
int main(){
    int lower=0,upper=300,difference=20,presentTemp;
    presentTemp=lower;
    printf("Fahrenheit to celsius conversion table\n");
    while(presentTemp<=upper){
        printf("%3d %6.2f\n",presentTemp,((5.00/9.00)*(presentTemp-32.00)));
        presentTemp+=difference;
    }
}