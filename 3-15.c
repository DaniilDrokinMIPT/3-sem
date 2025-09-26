#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Error: Wrong number of arguments!\nUsage: %s <input_file> <output_file> <lines>\n", argv[0]);
        return 1;
    }

    FILE *in = fopen(argv[1], "r");
    if (!in) {
        printf("Error: File %s does not exist!\n", argv[1]);
        return 1;
    }

    int start, end;
    if (strchr(argv[3], ':')) {
        if (sscanf(argv[3], "%d:%d", &start, &end) != 2 || start >= end) {
            printf("Error: Wrong lines format!\n");
            fclose(in);
            return 1;
        }
    } else {
        if (sscanf(argv[3], "%d", &start) != 1) {
            printf("Error: Wrong lines format!\n");
            fclose(in);
            return 1;
        }
        end = start + 1;
    }

    FILE *out = fopen(argv[2], "w");
    char line[1024];
    int line_num = 1;
    while (fgets(line, sizeof(line), in)) {
        if (line_num >= start && line_num < end) {
            fputs(line, out);
        }
        line_num++;
    }
    fclose(in);
    fclose(out);
    return 0;
}
