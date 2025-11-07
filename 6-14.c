#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned char r, g, b;
} Pixel;

Pixel get_pixel(Pixel* image, int width, int height, int x, int y) {
    if (x < 0) x = 0;
    if (x >= width) x = width - 1;
    if (y < 0) y = 0;
    if (y >= height) y = height - 1;
    return image[y * width + x];
}

int main(int argc, char** argv) {
    if (argc != 3) return 1;

    int n = atoi(argv[2]);

    FILE* f = fopen(argv[1], "rb");
    char format[3];
    int width, height, maxval;
    fscanf(f, "%2s\n%d %d\n%d\n", format, &width, &height, &maxval);

    Pixel* image = malloc(width * height * sizeof(Pixel));
    Pixel* temp = malloc(width * height * sizeof(Pixel));
    fread(image, sizeof(Pixel), width * height, f);
    fclose(f);

    float kernel[3][3] = {
        {1.0/9, 1.0/9, 1.0/9},
        {1.0/9, 1.0/9, 1.0/9},
        {1.0/9, 1.0/9, 1.0/9}
    };

    for (int iter = 0; iter < n; iter++) {
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                float r = 0, g = 0, b = 0;

                for (int dy = -1; dy <= 1; dy++) {
                    for (int dx = -1; dx <= 1; dx++) {
                        Pixel p = get_pixel(image, width, height, x + dx, y + dy);
                        r += p.r * kernel[dy + 1][dx + 1];
                        g += p.g * kernel[dy + 1][dx + 1];
                        b += p.b * kernel[dy + 1][dx + 1];
                    }
                }

                temp[y * width + x].r = (unsigned char)r;
                temp[y * width + x].g = (unsigned char)g;
                temp[y * width + x].b = (unsigned char)b;
            }
        }
        memcpy(image, temp, width * height * sizeof(Pixel));
    }

    FILE* out = fopen("result.ppm", "wb");
    fprintf(out, "P6\n%d %d\n%d\n", width, height, maxval);
    fwrite(image, sizeof(Pixel), width * height, out);
    fclose(out);
    free(image);
    free(temp);

    return 0;
}
