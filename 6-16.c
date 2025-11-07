#include <stdio.h>
#include <stdlib.h>
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

void draw_tree(Color* data, int width, int height, int x, int y, double angle, int depth, Color c) {
    if (depth == 0) return;

    int length = 10 * depth;
    int x2 = x + length * cos(angle);
    int y2 = y + length * sin(angle);

    draw_line(data, width, height, x, y, x2, y2, c);

    draw_tree(data, width, height, x2, y2, angle - 0.3, depth - 1, c);
    draw_tree(data, width, height, x2, y2, angle + 0.3, depth - 1, c);
}

int main() {
    int width = 800, height = 600;
    Color* canvas = calloc(width * height, sizeof(Color));

    for (int i = 0; i < width * height; i++) {
        canvas[i] = (Color){255, 255, 255};
    }

    Color brown = {139, 69, 19};
    draw_tree(canvas, width, height, width / 2, height - 50, -M_PI / 2, 10, brown);

    FILE* f = fopen("tree.ppm", "wb");
    fprintf(f, "P6\n%d %d\n255\n", width, height);
    fwrite(canvas, sizeof(Color), width * height, f);
    fclose(f);
    free(canvas);

    return 0;
}
