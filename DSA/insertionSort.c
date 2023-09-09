#include<stdio.h>
void insertionSort(int arr[], int size){
    for(int i=1;i<size;i++){
        int key = arr[i];
        int j = i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]= arr[j];
            j--;;
        }
        arr[j+1]=key;
        
    }
}
int main(){
    int arr[]={9,2,3,4,5,6,7,8,9};
    int size = sizeof(arr)/sizeof(arr[0]);
    insertionSort(arr, size);
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}