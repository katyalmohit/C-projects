#include <stdio.h>

int minFunction(int val1, int val2){
    if(val1<val2){
        return val1;
    }
    else{
        return val2;
    }
}

void main(){
    int n=5;
    int inf = 9999;
    int adj[5][5]={
            {0, 4, 5, inf, inf},
            {3, 0, inf, 2, inf},
            {inf, inf, 0, 2, inf},
            {inf, 6, inf, 0, 4},
            {inf, 5, inf, 7, 0}
        };
    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                adj[i][j]= minFunction(adj[i][j], adj[i][k]+ adj[k][j]);
            }
        }
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            printf("%d\t",adj[i][j]);
        }
        printf("\n");
    }
}
