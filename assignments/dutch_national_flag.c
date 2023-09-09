#include<stdio.h>
void sort(int arr[], int size);
int main(){
    int low, mid, high;
    int arr[]={1,2,0,2,2,1,1,0,1,0,1,2,1,2,1,0,0,0};
    int size = sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    sort(arr, size);
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
void sort(int arr[], int size){
    int low = 0, mid = 0, high = size-1;
    while(mid<=high){
        switch(arr[mid]){
            case 0:
                arr[mid] = arr[low];
                arr[low] = 0;
                low++;
                mid++;
                break;
            case 1:
                mid++;
                break;
            case 2:
                arr[mid] = arr[high];
                arr[high] = 2;
                high--;
                break;
        }
    }
}