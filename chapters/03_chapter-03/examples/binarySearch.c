//write a program to perform binary search on a sorted array
#include <stdio.h>
int binarySearch(int array[],int length, int toBeFound){
    int lower,upper,mid;
    lower = 0;  
    upper = length-1;
    while(lower<=upper){
        mid = (lower+upper)/2;
        if(toBeFound>array[mid]){
            lower=mid+1;
        }
        else if(toBeFound<array[mid]){
            upper=mid-1;
        }
        else if(array[mid]==toBeFound){
            return mid;
        }
    }
    return -1;
}

int main(){
    int arr[]={1,2,3,4,5,6,7,8};
    printf("%d",binarySearch(arr,8,3));
}