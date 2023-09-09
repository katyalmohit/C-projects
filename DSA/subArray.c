#include<stdio.h>
int subArray(int arr[], int size, int sum){
    int curSum = arr[0], start=0, i;
    for(i =1;i<=size;i++){
        
        while(curSum >sum){
            curSum -= arr[start];
            start++;
        }
        if(curSum == sum){
            for(int j=start; j<i;j++){
                printf("%d ",arr[j]);
            }
            return 1;
        }
        if(i<size){
            curSum += arr[i];
        }
    }
    printf("No sub array found");
    return 0;
}
int main(){
    int arr[]={9,2,3,4,5,6,7,8,9};
    int sum = 15;
    int size = sizeof(arr)/sizeof(arr[0]);
    subArray(arr, size, sum);
    return 0;
}