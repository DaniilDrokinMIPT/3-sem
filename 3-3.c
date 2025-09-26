#include <stdio.h>
#include <ctype.h>
#include <string.h>


void version_a() {
    char c;
    printf("Enter character: ");
    scanf("%c", &c);

    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
        printf("Letter\n");
    } else if (c >= '0' && c <= '9') {
        printf("Digit\n");
    } else {
        printf("Other\n");
    }
}


void version_b() {
    char c;
    printf("Enter character: ");
    scanf(" %c", &c);

    char letters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    char digits[] = "0123456789";
    int is_letter = 0, is_digit = 0;

    for (int i = 0; letters[i]; i++) {
        if (c == letters[i]) is_letter = 1;
    }
    for (int i = 0; digits[i]; i++) {
        if (c == digits[i]) is_digit = 1;
    }

    if (is_letter) printf("Letter\n");
    else if (is_digit) printf("Digit\n");
    else printf("Other\n");
}


void version_c() {
    char c;
    printf("Enter character: ");
    scanf(" %c", &c);

    if (isalpha(c)) printf("Letter\n");
    else if (isdigit(c)) printf("Digit\n");
    else printf("Other\n");
}

int main() {
    printf("Version (a):\n");
    version_a();

    printf("\nVersion (b):\n");
    version_b();

    printf("\nVersion (c):\n");
    version_c();

    return 0;
}
