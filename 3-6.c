#include <stdio.h>
#include <string.h>
#include <ctype.h>

int is_palindrome(const char *str) {
    int l = 0, r = strlen(str) - 1;
    while (l < r) {
        if (str[l] != str[r]) return 0;
        l++;
        r--;
    }
    return 1;
}

int main() {
    char word[100];

    printf("Enter word: ");
    scanf("%s", word);

    if (is_palindrome(word)) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}
