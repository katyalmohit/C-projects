#include<stdio.h>

void selectionSort(int ratio[], int size, int x[], int p[], int w[]){
    for(int i=0;i<size-1;i++){
        int min = i;
        for(int j=i+1;j<size;j++){
            if(ratio[j]<ratio[min]){
                min = j;
            }
        }
        int temp1 = ratio[i];
        int temp2 = x[i];
        int temp3 = p[i];
        int temp4 = w[i];

        ratio[i]= ratio[min];
        x[i] = x[min];
        p[i] = p[min];
        w[i] = w[min];

        ratio[min]= temp1;
        x[min]= temp2;
        p[min]= temp3;
        w[min]= temp4;
    }
}
void main(){
    int x[]={1, 2, 3, 4};
    int p[]={5, 9, 4, 8};
    int w[]={1, 3, 2, 2};
    int weight=4;

    int size = sizeof(x)/sizeof(x[0]);
    int ratio[size];
    for(int i=0; i<size; i++){
        ratio[i]=p[i]/w[i];
    }
    selectionSort(ratio, size, x, p, w);
    for(int i=0; i<size; i++){
        printf("x: %d\n", x[i]);
        printf("ratio: %d\n", ratio[i]);
    }
    
}