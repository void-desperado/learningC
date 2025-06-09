//fahrenheit to celsius conversion table using for loop
#include <stdio.h>
int main(){
    int lower=0,upper=300,difference=20,presentTemp;
    for(presentTemp=upper;presentTemp>=lower;presentTemp-=difference){
        printf("%3d %6.2f\n",presentTemp,((5.00/9.00)*(presentTemp-32.00)));
    }
}