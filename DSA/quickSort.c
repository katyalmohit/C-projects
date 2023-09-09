#include<stdio.h>
void quickSort(int arr[], int low, int high){
    if(low<high){
        int pivot = arr[low];
        int start = low;
        int end = high;
        while(start<end){
            while(arr[start]<=pivot){
                start++;
            }
            while(arr[end]>pivot){
                end--;
            }
            if(start<end){
                int temp = arr[start];
                arr[start]= arr[end];
                arr[end]= temp;
            }
        }
        int temp = arr[low];
        arr[low]= arr[end];
        arr[end]= temp;
        quickSort(arr, low, end-1);
        quickSort(arr, end+1, high);

    }
}
int main(){
    int arr[]={9,2,3,4,5,6,7,8,9};
    int size = sizeof(arr)/sizeof(arr[0]);
    quickSort(arr, 0, size-1);
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}