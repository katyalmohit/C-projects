#include<stdio.h>

int minFunction(int val1, int val2){
    if(val1<val2){
        return val1;
    }
    else{
        return val2;
    }
}

void main(){
    int n=4;
    int inf = 9999;
    int adj[4][4]={
        {0, 2, 9, inf},
        {1, 0, 6, 3},
        {inf, 7, 0, 8},
        {6, 4, inf, 0}
    };
    printf()
}