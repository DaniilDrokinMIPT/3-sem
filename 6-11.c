#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned char r, g, b;
} Pixel;

int main(int argc, char** argv) {
    if (argc != 2) return 1;

    FILE* f = fopen(argv[1], "rb");
    if (!f) return 1;

    char format[3];
    int width, height, maxval;
    fscanf(f, "%2s\n%d %d\n%d\n", format, &width, &height, &maxval);

    Pixel* image = malloc(width * height * sizeof(Pixel));
    fread(image, sizeof(Pixel), width * height, f);
    fclose(f);

    for (int i = 0; i < width * height; i++) {
        unsigned char gray = 0.299 * image[i].r + 0.587 * image[i].g + 0.114 * image[i].b;
        image[i].r = image[i].g = image[i].b = gray;
    }

    FILE* out = fopen("result.ppm", "wb");
    fprintf(out, "P6\n%d %d\n%d\n", width, height, maxval);
    fwrite(image, sizeof(Pixel), width * height, out);
    fclose(out);
    free(image);

    return 0;
}
