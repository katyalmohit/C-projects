#include<stdio.h>
void spiral(int matrix[][4], int row, int column){
    int left = 0; int right = column-1;
    int top = 0; int bottom = row-1;
    while(top<=bottom && left <=right){
        for(int i=left; i<=right; i++){
            printf("%d ", matrix[top][i]);
        }
        top++;
        for(int j= top;j<=bottom; j++){
            printf("%d ", matrix[j][right]);
        }
        right--;
        if(left<=right){
            for(int i= right;i>=left; i--){
                printf("%d ", matrix[bottom][i]);
            }
            bottom--;
        }
        if(top<=bottom){
            for(int j= bottom; j>=top; j--){
                printf("%d ",matrix[j][left]);
            }
            left++;
        }
    }
}
int main(){
    int matrix[4][4] ={{1,2,3,4},
                     {5,6,7,8},
                     {9,10,11,12},
                     {13,14,15,16}};
    int rows = 4;
    int columns = 4;
    spiral(matrix, 4,4 );
    return 0;

}