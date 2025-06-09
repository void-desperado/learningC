#include <stdio.h>
int power(int base,int exponent){
    int result=1;
    for(int i=0;i<exponent;i++){
        result*=base;
    }
    return result;
}
int main(){
    int m,n;
    printf("Enter the base: ");
    scanf("%d",&m);
    printf("Enter the power: ");
    scanf("%d",&n);
    printf("The result of base raised to power is: %d",power(m,n));
}