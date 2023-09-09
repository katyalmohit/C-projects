#include<stdio.h>
void selectionSort(int arr[], int size){
    for(int i=0;i<size-1;i++){
        int min = i;
        for(int j=i+1;j<size;j++){
            if(arr[j]<arr[min]){
                min = j;
            }
        }
        int temp = arr[i];
        arr[i]= arr[min];
        arr[min]= temp;
    }
}
int main(){
    int arr[]={9,2,3,4,5,6,7,8,9};
    int size = sizeof(arr)/sizeof(arr[0]);
    selectionSort(arr, size);
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}