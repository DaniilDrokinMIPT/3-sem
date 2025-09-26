#include <stdio.h>

void trim_after_first_space(char str[]) {
    for (int i = 0; str[i]; i++) {
        if (str[i] == ' ') {
            str[i] = '\0';
            return;
        }
    }
}

int main() {
    char a[] = "Cats and Dogs";
    printf("Before: %s\n", a);
    trim_after_first_space(a);
    printf("After: %s\n", a);

    return 0;
}
