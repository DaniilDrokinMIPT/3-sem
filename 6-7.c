#include <stdio.h>

int main(int argc, char** argv) {
    if (argc != 2) return 1;
    FILE* f = fopen(argv[1], "rb");
    fseek(f, 0, SEEK_END);
    printf("%ld\n", ftell(f));
    fclose(f);
    return 0;
}
