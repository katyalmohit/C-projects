#include <stdio.h>

int maxFunction(int val1, int val2){
    if (val1> val2){
        return val1;
    }
    else {
        return val2;
    }
}
int knapSack(int n, int profit[], int weight[], int maxWeight, int M[][151]){
    for(int i=0; i<=n; i++){
        for(int j=0; j<=maxWeight; j++){
            if(i==0 || j==0){
                M[i][j] = 0;
            }
            else if(j>=weight[i-1]){
                M[i][j]= maxFunction(M[i-1][j], M[i-1][j-weight[i-1]]+profit[i-1]);
            }
            else{
                M[i][j]= M[i-1][j];
            }
        }
    }
    return M[n][maxWeight];
}
int main(){
    int n=9;
    int profit[]= {80, 23, 8, 12, 18, 5, 20, 40, 14};
    int weight[]= {15, 45, 10, 7, 18, 36, 28, 21, 16};
    int maxWeight = 150;
    int M[10][151];
    int maxValue = knapSack(n, profit, weight, maxWeight, M);
    printf("Maximum Value: %d\n", maxValue);
    return 0;
}