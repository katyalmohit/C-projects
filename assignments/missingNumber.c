#include<stdio.h>
int missingNumber(int arr[], int numsSize){
    int sum = 0;
    for(int i=0; i<numsSize; i++){
        sum+=arr[i];
    }
    int naturalSum = ((numsSize+1)*(numsSize))/2;
    int missNumber = naturalSum - sum;
    return missNumber;
}
int main(){
    int arr[] = {0,1,2,3,4,5,6,7,9};
    int numsSize = sizeof(arr)/sizeof(arr[0]);
    int missNumber = missingNumber(arr, numsSize);
    printf("Missing number is %d\n", missNumber);
    return 0;
}