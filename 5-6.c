#include <stdio.h>
#include <stdlib.h>

typedef int (*Comparator)(int, int);

void sort(int* a, size_t n, Comparator cmp) {
    for (size_t i = 0; i < n-1; i++) {
        for (size_t j = i+1; j < n; j++) {
            if (cmp(a[i], a[j]) > 0) {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

int less(int a, int b) { return a - b; }
int greater(int a, int b) { return b - a; }
int last_digit_less(int a, int b) { return (a % 10) - (b % 10); }

void print(int* a, size_t n) {
    for (size_t i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main() {
    int a[] = {32, 63, 29, 54, 81};
    sort(a, 5, less);
    print(a, 5);
    sort(a, 5, greater);
    print(a, 5);
    sort(a, 5, last_digit_less);
    print(a, 5);
    return 0;
}
