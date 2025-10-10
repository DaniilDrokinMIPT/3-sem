#include <stdio.h>
#include <stdlib.h>

float* get_geometric_progression(float a, float r, int n) {
    float* arr = malloc(n * sizeof(float));
    for (int i = 0; i < n; i++) {
        arr[i] = a;
        a *= r;
    }
    return arr;
}

int main() {
    float* progression = get_geometric_progression(3.0, 3.0, 10);
    for (int i = 0; i < 10; i++) {
        printf("%.0f ", progression[i]);
    }
    free(progression);
    return 0;
}
