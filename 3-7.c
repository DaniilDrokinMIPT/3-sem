#include <stdio.h>
#include <ctype.h>

void encrypt(char *str, int k) {
    k = k % 26;
    if (k < 0) k += 26;

    for (int i = 0; str[i]; i++) {
        if (isupper(str[i])) {
            str[i] = (str[i] - 'A' + k) % 26 + 'A';
        } else if (islower(str[i])) {
            str[i] = (str[i] - 'a' + k) % 26 + 'a';
        }

    }
}

int main() {
    char text[1000];
    int key;

    printf("Enter key: ");
    scanf("%d", &key);
    printf("Enter text: ");
    scanf(" %[^\n]", text);

    encrypt(text, key);
    printf("Encrypted: %s\n", text);

    return 0;
}
