#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void encrypt_file(FILE *in, FILE *out, int key) {
    int ch;
    while ((ch = fgetc(in)) != EOF) {
        if (isupper(ch))
            ch = (ch - 'A' + key) % 26 + 'A';
        else if (islower(ch))
            ch = (ch - 'a' + key) % 26 + 'a';
        fputc(ch, out);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input> <output> <key>\n", argv[0]);
        return 1;
    }
    FILE *in = fopen(argv[1], "r");
    FILE *out = fopen(argv[2], "w");
    int key = atoi(argv[3]);
    encrypt_file(in, out, key);
    fclose(in);
    fclose(out);
    return 0;
}
