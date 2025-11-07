#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

typedef struct {
    unsigned char r, g, b;
} Color;

void draw_line(Color* data, int width, int height, int x0, int y0, int x1, int y1, Color c) {
    int dx = abs(x1 - x0), sx = x0 < x1 ? 1 : -1;
    int dy = abs(y1 - y0), sy = y0 < y1 ? 1 : -1;
    int err = (dx > dy ? dx : -dy) / 2;

    while (1) {
        if (x0 >= 0 && x0 < width && y0 >= 0 && y0 < height) {
            data[y0 * width + x0] = c;
        }

        if (x0 == x1 && y0 == y1) break;
        int e2 = err;
        if (e2 > -dx) { err -= dy; x0 += sx; }
        if (e2 < dy) { err += dx; y0 += sy; }
    }
}

int main(int argc, char** argv) {
    if (argc != 2) return 1;

    int n = atoi(argv[1]);
    int width = 800, height = 600;
    Color* canvas = calloc(width * height, sizeof(Color));

    for (int i = 0; i < width * height; i++) {
        canvas[i] = (Color){255, 255, 255};
    }

    srand(time(NULL));

    for (int i = 0; i < n; i++) {
        Color c = {rand() % 256, rand() % 256, rand() % 256};
        int x0 = rand() % width, y0 = rand() % height;
        int x1 = rand() % width, y1 = rand() % height;
        draw_line(canvas, width, height, x0, y0, x1, y1, c);
    }

    FILE* f = fopen("randlines.ppm", "wb");
    fprintf(f, "P6\n%d %d\n255\n", width, height);
    fwrite(canvas, sizeof(Color), width * height, f);
    fclose(f);
    free(canvas);

    return 0;
}
