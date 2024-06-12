#include <stdio.h>

void strassenMatrixMultiplication(int A[2][2], int B[2][2], int C[2][2]) {
    int M1, M2, M3, M4, M5, M6, M7;

    M1 = (A[0][0] + A[1][1]) * (B[0][0] + B[1][1]);
    M2 = (A[1][0] + A[1][1]) * B[0][0];
    M3 = A[0][0] * (B[0][1] - B[1][1]);
    M4 = A[1][1] * (B[1][0] - B[0][0]);
    M5 = (A[0][0] + A[0][1]) * B[1][1];
    M6 = (A[1][0] - A[0][0]) * (B[0][0] + B[0][1]);
    M7 = (A[0][1] - A[1][1]) * (B[1][0] + B[1][1]);

    C[0][0] = M1 + M4 - M5 + M7;
    C[0][1] = M3 + M5;
    C[1][0] = M2 + M4;
    C[1][1] = M1 - M2 + M3 + M6;
}

int main() {
    int A[2][2] = {{1, 1}, {2, 2}};
    int B[2][2] = {{3, 4}, {2, 1}};
    int C[2][2];

    printf("The first matrix is: \n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }

    printf("The second matrix is: \n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%d ", B[i][j]);
        }
        printf("\n");
    }

    strassenMatrixMultiplication(A, B, C);

    printf("Product achieved using Strassen's algorithm: \n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}
