#include<stdio.h>
#include<stdbool.h>

void bubbleSort(int arr[], int size){
    int temp;
    for(int i=0; i<size; i++){
        for(int j=0; j<size-i-1; j++){
            if(arr[j]>arr[j+1]){
                temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main(){
    int array1[] = {1, 0, 2, 5, 9, 3};
    int n1 = (sizeof(array1)/(sizeof(array1[0])));

    int array2[] = {2, 4, 5, 6,};
    int n2 = (sizeof(array2)/(sizeof(array2[0])));

    bool flag = true;
    printf("\nArray1:  ");
    for(int i=0;i<n1; i++){
        printf("%d   ", array1[i]);
    }

    printf("\n");

    printf("Array2:  ");
    for(int i=0;i<n2; i++){
        printf("%d   ", array2[i]);
    }

    int c = n1 + n2;
    int array3[c];

    for(int i=0; i<n1; i++){
        array3[i] = array1[i];
    }

    int j = 0;
    for(int i=n1; i<c; i++){
        array3[i] = array2[j];
        j++;
    }

    printf("\nCombined array:   ");    
    for(int i=0; i<c; i++){
        printf("%d   ", array3[i]);
    }

    bubbleSort(array3, c);

    printf("\nSorted array:   ");
    for(int i=0; i<c; i++){
        printf("%d   ", array3[i]);
    }

    return 0;
}