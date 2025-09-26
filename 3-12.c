#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <word> <count>\n", argv[0]);
        return 1;
    }
    int count = atoi(argv[2]);
    for (int i = 0; i < count; i++) {
        printf("%s ", argv[1]);
    }
    printf("\n");
    return 0;
}
