//functions to convert celsius to fahrenheit and fahrenheit to celsius
#include <stdio.h>
int celsiusToFahrenheit(int celsius){
    return (32+((9.00/5.00)*celsius));
}

int fahrenheitToCelsius(int fahrenheit){
    return ((5.00/9.00)*(fahrenheit-32.00));
}