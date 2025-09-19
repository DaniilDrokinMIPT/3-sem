#include <stdio.h>

void assign(float A[MAX][MAX], float B[MAX][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            A[i][j] = B[i][j];
        }
    }
}
