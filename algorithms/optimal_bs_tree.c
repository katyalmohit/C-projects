#include<stdio.h>

int minFunction(int val1, int val2){
    if(val1<=val2){
        return val1;
    }
    else{
        return val2;
    }
}

void main(){
    int n=6;
    int keys[]={0, 1, 2, 3, 4, 5, 6};
    float P[]={-1, 0.1, 0.05, 0.1, 0.15, 0.1, 0.1};
    float Q[]={0.1, 0.03, 0.02, 0.07, 0.06, 0.1, 0.02};
    float weight[n+1][n+2];
    float cost[n+1][n+2];
    int root[n+1][n+2];

    //Initializing all values to zero
    for(int i=0; i<n+1; i++){
        for(int j=0; j<n+2; j++){
            weight[i][j]=0;
            cost[i][j]=0;
            root[i][j]=0;
        }
    }
    
    //Calculating the weight matrix
    for(int i=0; i<n+1; i++){
        for(int j=1; j<=n+1; j++){
            if(i==j-1){
                weight[i][j]=Q[j-1];
            }
            else if(i==j){
                weight[i][j]=weight[i-1][j]+P[i]+Q[i];
            }
            else if(j<i){
                weight[i][j]=weight[i-1][j]+P[i]+Q[i];
            }
        }
    }

    //calculating cost matrix

    //when (i==j-1)
    for(int i=0; i<n+1; i++){
        for(int j=1; j<=n+1; j++){
            if(i==j-1){
                cost[i][j]= weight[i][j];
            }
        }
    }
    //when (i==j)
    for(int i=0; i<n+1; i++){
        for(int j=1; j<=n+1; j++){
            if(i==j){
                int r=i;
                cost[i][j]= cost[r-1][i]+cost[j][r+1]+weight[i][j];
            }
        }
    }

    //when (j<i)
    // int minCost=0;
    for(int i=0; i<n+1; i++){
        for(int j=1; j<=n+1; j++){
            if(i==2&&j==1){
                
                for(int r=j; r<i; r++){
                    int minCost =0;
                    cost[i][j]= cost[r-1][j]+cost[i][r+1]+weight[i][j];
                     minCost = cost[i][j];
                    printf("%.2f", minCost);
                    // printf("%.2f", cost[i][j]);
                    
                    // if(minCost!=0 && cost[i][j]< minCost){
                    //     minCost = cost[i][j];
                    //     root[i][j]= r;
                    //     // printf("%d", r);
                    //     // printf("%d", minCost);
                    // }
                    
                }
               
                
                // cost[i][j]= minCost;
                // int r=1;
                // cost[i][j]= cost[r-1][j]+cost[i][r+1]+weight[i][j];
                // printf("%.2f", cost[i][j]);
            }
        }
    }

    for(int i=0; i<n+1; i++){
        for(int j=1; j<=n+1; j++){
            // printf("%.2f ",weight[i][j]);
            // printf("%.2f ",cost[i][j]);
        }
        printf("\n");
    }


}