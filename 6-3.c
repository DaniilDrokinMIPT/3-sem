#include <stdio.h>
#include <string.h>

int main() {
    int a[4] = {1819043144, 1461726319, 1684828783, 2593};

    printf("%s\n", (char*)a);

    union {
        int i[4];
        char s[16];
    } u;
    memcpy(u.i, a, 16);
    printf("%s\n", u.s);

    char str[17];
    memcpy(str, a, 16);
    str[16] = '\0';
    printf("%s\n", str);

    return 0;
}
