#include <stdio.h>

void multiply(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = 0;
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void assign(int A[MAX][MAX], int B[MAX][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            A[i][j] = B[i][j];
        }
    }
}

void power(int A[MAX][MAX], int C[MAX][MAX], int n, int k) {
    int temp[MAX][MAX];
    int result[MAX][MAX];
    assign(result, A, n);
    for (int p = 1; p < k; p++) {
        multiply(result, A, temp, n);
        assign(result, temp, n);
    }
    assign(C, result, n);
}
