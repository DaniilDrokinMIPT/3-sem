#include <stdio.h>
#include <string.h>

int main() {
    char s1[100], s2[100];
    printf("Enter two words: ");
    scanf("%s %s", s1, s2);

    int len1 = strlen(s1), len2 = strlen(s2);
    int max_len = len1 > len2 ? len1 : len2;

    for (int i = 0; i < max_len; i++) {
        if (i < len1) putchar(s1[i]);
        if (i < len2) putchar(s2[i]);
    }
    printf("\n");

    return 0;
}
