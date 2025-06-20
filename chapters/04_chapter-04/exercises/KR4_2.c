#include <ctype.h> 

int powerFunction(int base,int exponent){
    int result=1;
    for(int i=0;i<exponent;i++){
        result*=base;
    }
    return result;
}

double atof(char s[]) 
{ 
    double val, power,v1,power2,v2; 
    int i, sign,sign2; 
    for (i = 0; isspace(s[i]); i++)
        ; 
    sign = (s[i] == '-') ? -1 : 1; 
    if (s[i] == '+' || s[i] == '-') 
        i++; 
    for (val = 0.0; isdigit(s[i]); i++) 
        val = 10.0 * val + (s[i] - '0'); 
    if (s[i] == '.') 
        i++; 
    for (power = 1.0; isdigit(s[i]); i++) { 
        val = 10.0 * val + (s[i] - '0'); 
        power *= 10; 
    } 
    v1 = sign * val / power;
    if(s[i]=='e' || s[i]=='E')
        i++;
    sign2 = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-') 
        i++; 
    for (power2 = 0.0; isdigit(s[i]); i++) 
        power2 = 10.0 * power2 + (s[i] - '0'); 
    if(sign2==+1)
        v2=v1*powerFunction(10,power2);
    else
        v2=v1/powerFunction(10,power2);
} 