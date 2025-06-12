//write a program to perform binary search on a sorted array with only one test condition inside the loop
#include <stdio.h>
int binarySearch(int array[],int length, int toBeFound){
    int lower,upper,mid;
    lower = 0;  
    upper = length-1;
    mid = (lower+upper)/2;
    while(lower<=upper){
        mid = (lower+upper)/2;
        if(toBeFound>array[mid]){
            lower=mid+1;
        }
        else{
            upper=mid-1;
        }
    }
    if(array[lower]==toBeFound)
        return lower;
    else
        return -1;
}

int main(){
    int arr[]={1,2,3,4,5,6,7,8};
    printf("%d",binarySearch(arr,8,8));
}