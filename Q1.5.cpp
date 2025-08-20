#include <stdio.h>

int main() {
    int a[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int rowSum, colSum;

    for (int i = 0; i < 3; i++) {
        rowSum = 0;
        for (int j = 0; j < 3; j++)
            rowSum += a[i][j];
        printf("Sum of row %d = %d\n", i+1, rowSum);
    }

    for (int i = 0; i < 3; i++) {
        colSum = 0;
        for (int j = 0; j < 3; j++)
            colSum += a[j][i];
        printf("Sum of column %d = %d\n", i+1, colSum);
    }
    return 0;
}
