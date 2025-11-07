#include <stdio.h>

int main(int argc, char** argv) {
    if (argc != 2) return 1;
    FILE* f = fopen(argv[1], "rb");
    fseek(f, -3, SEEK_END);
    for (int i = 0; i < 3; i++) putchar(fgetc(f));
    fclose(f);
    return 0;
}
