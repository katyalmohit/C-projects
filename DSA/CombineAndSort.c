#include<stdio.h>
int combineAndSort(int arr1[], int arr2[], int size1, int size2){
    int size3 = size1+size2;
    int arr3[size3];
    for(int i=0;i<size1;i++){
        arr3[i]=arr1[i];
    }
    for(int i=0;i<size2;i++){
        arr3[i+size1]=arr2[i];
    }
    for(int i=0;i<size3;i++){
        printf("%d ",arr3[i]);
    }
    printf("\n");
    for(int i=1;i<size3;i++){
        int key = arr3[i];
        int j = i-1;
        while(j>=0 && arr3[j]>key){
            arr3[j+1]= arr3[j];
            j--;;
        }
        arr3[j+1]=key;
        
    }
    for(int i=0;i<size3;i++){
        printf("%d ",arr3[i]);
    }
    printf("\n");
    return 0;
    
}
int main(){
    int arr1[]={1,2,3,4,5,6,7,8,9};
    int arr2[]={9,8,7,6,5,4,3,2,1};
    int size1 = sizeof(arr1)/sizeof(arr1[0]);
    int size2 = sizeof(arr2)/sizeof(arr2[0]);
    combineAndSort(arr1,arr2,size1,size2);
    return 0;

}