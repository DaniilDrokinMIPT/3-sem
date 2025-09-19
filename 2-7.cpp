#include <stdio.h>

int count_even(int arr[], int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) {
            count++;
        }
    }
    return count;
}

int main() {
    int arr1[] = {1, 2, 3, 4, 5};
    printf("%d\n", count_even(arr1, 5));
    return 0;
}
