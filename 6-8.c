#include <stdio.h>

typedef struct { unsigned char r, g, b; } Color;

int main() {
    int width = 600, height = 400;
    Color white = {255, 255, 255}, red = {190, 0, 41};
    FILE* f = fopen("flag.ppm", "wb");
    fprintf(f, "P6\n%d %d\n255\n", width, height);

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int dx = x - width/2, dy = y - height/2;
            if (dx*dx + dy*dy < 10000) fwrite(&red, 3, 1, f);
            else fwrite(&white, 3, 1, f);
        }
    }
    fclose(f);
    return 0;
}
