#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct { unsigned char r, g, b; } Color;

void draw_circle(Color* data, int width, int height, int x0, int y0, int r, Color c) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int dx = x - x0, dy = y - y0;
            if (dx*dx + dy*dy <= r*r) data[y*width + x] = c;
        }
    }
}

int main(int argc, char** argv) {
    if (argc != 4) return 1;
    int n = atoi(argv[1]), a = atoi(argv[2]), b = atoi(argv[3]);
    int width = 500, height = 500;
    Color* canvas = calloc(width*height, sizeof(Color));
    srand(time(NULL));

    for (int i = 0; i < n; i++) {
        Color c = {rand()%256, rand()%256, rand()%256};
        int x0 = rand()%width, y0 = rand()%height, r = a + rand()%(b-a+1);
        draw_circle(canvas, width, height, x0, y0, r, c);
    }

    FILE* f = fopen("circles.ppm", "wb");
    fprintf(f, "P6\n%d %d\n255\n", width, height);
    fwrite(canvas, 3, width*height, f);
    fclose(f);
    free(canvas);
    return 0;
}
