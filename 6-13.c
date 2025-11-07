#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned char r, g, b;
} Pixel;

unsigned char clamp(float value) {
    if (value > 255) return 255;
    if (value < 0) return 0;
    return (unsigned char)value;
}

int main(int argc, char** argv) {
    if (argc != 2) return 1;

    FILE* f = fopen(argv[1], "rb");
    char format[3];
    int width, height, maxval;
    fscanf(f, "%2s\n%d %d\n%d\n", format, &width, &height, &maxval);

    Pixel* image = malloc(width * height * sizeof(Pixel));
    fread(image, sizeof(Pixel), width * height, f);
    fclose(f);

    for (int i = 0; i < width * height; i++) {
        float r = image[i].r, g = image[i].g, b = image[i].b;

        float new_r = 0.393 * r + 0.769 * g + 0.189 * b;
        float new_g = 0.349 * r + 0.686 * g + 0.168 * b;
        float new_b = 0.272 * r + 0.534 * g + 0.131 * b;

        image[i].r = clamp(new_r);
        image[i].g = clamp(new_g);
        image[i].b = clamp(new_b);
    }

    FILE* out = fopen("result.ppm", "wb");
    fprintf(out, "P6\n%d %d\n%d\n", width, height, maxval);
    fwrite(image, sizeof(Pixel), width * height, out);
    fclose(out);
    free(image);

    return 0;
}
