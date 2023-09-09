#include<stdio.h>
int recursiveBinarySearch(int arr[], int low, int high, int element){
    if (low<=high){
        int mid = (low+high)/2;
        if (arr[mid]==element){
            return mid;
        }
        if (arr[mid]<element){
            return recursiveBinarySearch(arr, mid+1, high, element);
        }
        else{
            return recursiveBinarySearch(arr, low, mid-1, element);
        }
    }
    return -1;
}
int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int size = sizeof(arr)/sizeof(int);
    int element = 5;
    int searchIndex = recursiveBinarySearch(arr, 0, size-1, element);
    printf("The element %d was found at index %d\n", element, searchIndex);
    return 0;
}