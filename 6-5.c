#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void save_numbers_text(const char* filename, double* array, int n) {
    FILE* f = fopen(filename, "w");
    fprintf(f, "%d\n", n);
    for (int i = 0; i < n; i++) fprintf(f, "%.15f\n", array[i]);
    fclose(f);
}

void save_numbers_binary(const char* filename, double* array, int n) {
    FILE* f = fopen(filename, "wb");
    fwrite(&n, sizeof(int), 1, f);
    fwrite(array, sizeof(double), n, f);
    fclose(f);
}
