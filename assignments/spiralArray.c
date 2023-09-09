#include<stdio.h>

void printMatrixSpirally( int row, int column, int matrix[][column]){
    int top = 0;
    int bottom = row-1;
    int left = 0;
    int right = column-1;
    while(top<=bottom && left<=right){
        for (int i = left; i<=right; i++){
            printf("%d ", matrix[top][i]);
        }
        top++;
        for (int i = top; i<=bottom; i++){
            printf("%d ", matrix[i][right]);
        }
        right--;
        if (top<=bottom){
            for (int i = right; i>=left; i--){
                printf("%d ", matrix[bottom][i]);
            }
            bottom--;
        }
        if (left<=right){
            for (int i = bottom; i>=top; i--){
                printf("%d ", matrix[i][left]);
            }
            left++;
        }
    }
}
int main(){
    int matrix[4][4] = {{1,2,3,4},
                        {5,6,7,8},
                        {9,10,11,12},
                        {13,14,15,16}};
    int row = 4;
    int column = 4;
    printMatrixSpirally(row, column, matrix);
    return 0;
}