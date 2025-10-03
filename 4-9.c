#include <stdio.h>
#include <ctype.h>
#include <string.h>

void used_chars(const char* str, char* used) {
    int letters[26] = {0};
    for (const char* p = str; *p; p++) {
        if (isalpha(*p)) {
            char lower = tolower(*p);
            letters[lower - 'a'] = 1;
        }
    }
    int index = 0;
    for (int i = 0; i < 26; i++) {
        if (letters[i]) {
            used[index++] = 'a' + i;
        }
    }
    used[index] = '\0';
}

int main() {
    char s[50] = "Sapere Aude";
    char u[30];
    used_chars(s, u);
    printf("%s\n", u);

    strcpy(s, "1231%0");
    used_chars(s, u);
    printf("%s\n", u);

    strcpy(s, "The Quick Brown Fox Jumps Over The Lazy Dog!");
    used_chars(s, u);
    printf("%s\n", u);

    return 0;
}
