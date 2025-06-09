//fahrenheit to celsius conversion table using for loop and define statement
#include <stdio.h>
#define UPPER 300
#define LOWER 0
#define DIFFERENCE 20
int main(){
    int presentTemp;
    for(presentTemp=LOWER;presentTemp<=UPPER;presentTemp+=DIFFERENCE){
        printf("%3d %6.2f\n",presentTemp,((5.00/9.00)*(presentTemp-32.00)));
    }
}