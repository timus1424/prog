#include <stdio.h>

int main() {
    int i,j;
    int A[4][6] = {
        {0,1,0,0,0,7},
        {0,0,0,2,0,0},
        {0,0,0,0,0,3},
        {4,0,0,0,5,0}
    };

    int rows = 4, cols = 6;

    int compact[25][3]; // enough space
    int t = 0; // nonzero count
    compact[0][0] = rows;
    compact[0][1] = cols;

    for (i=0;i<rows;i++) {
        for (j=0;j<cols;j++) {
            if (A[i][j] != 0) {
                t++;
                compact[t][0] = i+1;  // row
                compact[t][1] = j+1;  // col
                compact[t][2] = A[i][j];
            }
        }
    }
    compact[0][2] = t;

    printf("Compact form of original matrix:\n");
    for (int i=0;i<=t;i++)
        printf("%d %d %d\n", compact[i][0], compact[i][1], compact[i][2]);

    int B[6][4];
    for (i=0;i<rows;i++) {
        for (j=0;j<cols;j++) {
            B[j][i] = A[i][j];
        }
    }

    int transpose[25][3];
    int t2 = 0;
    transpose[0][0] = cols; 
    transpose[0][1] = rows; 

    for (i=0;i<cols;i++) {
        for (j=0;j<rows;j++) {
            if (B[i][j] != 0) {
                t2++;
                transpose[t2][0] = i+1;
                transpose[t2][1] = j+1;
                transpose[t2][2] = B[i][j];
            }
        }
    }
    transpose[0][2] = t2;

    printf("\nCompact form of transpose matrix:\n");
    for (i=0;i<=t2;i++)
        printf("%d %d %d\n", transpose[i][0], transpose[i][1], transpose[i][2]);

    int full = rows*cols;
    int compactSize = 3*(t+1);
    double gain = ((double)(full - compactSize)/full)*100.0;

    printf("\nMemory utilization gain = %.2f%%\n", gain);

    return 0;
}