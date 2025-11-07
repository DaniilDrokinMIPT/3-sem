#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
    unsigned char r, g, b;
} Pixel;

unsigned char clamp(float value) {
    if (value > 255) return 255;
    if (value < 0) return 0;
    return (unsigned char)value;
}

Pixel get_pixel(Pixel* image, int width, int height, int x, int y) {
    if (x < 0) x = 0;
    if (x >= width) x = width - 1;
    if (y < 0) y = 0;
    if (y >= height) y = height - 1;
    return image[y * width + x];
}

void apply_sepia(Pixel* image, int width, int height) {
    for (int i = 0; i < width * height; i++) {
        float r = image[i].r, g = image[i].g, b = image[i].b;

        float new_r = 0.393 * r + 0.769 * g + 0.189 * b;
        float new_g = 0.349 * r + 0.686 * g + 0.168 * b;
        float new_b = 0.272 * r + 0.534 * g + 0.131 * b;

        image[i].r = clamp(new_r);
        image[i].g = clamp(new_g);
        image[i].b = clamp(new_b);
    }
}

void apply_grayscale(Pixel* image, int width, int height) {
    for (int i = 0; i < width * height; i++) {
        unsigned char gray = 0.299 * image[i].r + 0.587 * image[i].g + 0.114 * image[i].b;
        image[i].r = image[i].g = image[i].b = gray;
    }
}

void apply_brighter(Pixel* image, int width, int height, int value) {
    for (int i = 0; i < width * height; i++) {
        image[i].r = clamp(image[i].r + value);
        image[i].g = clamp(image[i].g + value);
        image[i].b = clamp(image[i].b + value);
    }
}

void swap_colors(Pixel* image, int width, int height) {
    for (int i = 0; i < width * height; i++) {
        unsigned char temp = image[i].r;
        image[i].r = image[i].b;
        image[i].b = temp;
    }
}

void apply_blur(Pixel* image, int width, int height, int iterations) {
    Pixel* temp = malloc(width * height * sizeof(Pixel));

    float kernel[3][3] = {
        {1.0/9, 1.0/9, 1.0/9},
        {1.0/9, 1.0/9, 1.0/9},
        {1.0/9, 1.0/9, 1.0/9}
    };

    for (int iter = 0; iter < iterations; iter++) {
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
    free(temp);
}

void apply_mirror(Pixel* image, int width, int height) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width / 2; x++) {
            Pixel temp = image[y * width + x];
            image[y * width + x] = image[y * width + (width - 1 - x)];
            image[y * width + (width - 1 - x)] = temp;
        }
    }
}

int main(int argc, char** argv) {
    if (argc < 4) {
        printf("Usage: mge <effect> [params] <input> <output>\n");
        printf("Effects: --sepia, --bw, --brighter <value>, --changecolors, --blur <iterations>, --mirror\n");
        return 1;
    }

    char* effect = argv[1];
    char* input_file = argv[argc - 2];
    char* output_file = argv[argc - 1];

    FILE* f = fopen(input_file, "rb");
    if (!f) {
        printf("Cannot open input file\n");
        return 1;
    }

    char format[3];
    int width, height, maxval;
    fscanf(f, "%2s\n%d %d\n%d\n", format, &width, &height, &maxval);

    Pixel* image = malloc(width * height * sizeof(Pixel));
    fread(image, sizeof(Pixel), width * height, f);
    fclose(f);


    if (strcmp(effect, "--sepia") == 0) {
        apply_sepia(image, width, height);
    }
    else if (strcmp(effect, "--bw") == 0) {
        apply_grayscale(image, width, height);
    }
    else if (strcmp(effect, "--brighter") == 0 && argc > 4) {
        int value = atoi(argv[2]);
        apply_brighter(image, width, height, value);
    }
    else if (strcmp(effect, "--changecolors") == 0) {
        swap_colors(image, width, height);
    }
    else if (strcmp(effect, "--blur") == 0 && argc > 4) {
        int iterations = atoi(argv[2]);
        apply_blur(image, width, height, iterations);
    }
    else if (strcmp(effect, "--mirror") == 0) {
        apply_mirror(image, width, height);
    }
    else {
        printf("Unknown effect or missing parameters\n");
        free(image);
        return 1;
    }

    FILE* out = fopen(output_file, "wb");
    fprintf(out, "P6\n%d %d\n%d\n", width, height, maxval);
    fwrite(image, sizeof(Pixel), width * height, out);
    fclose(out);
    free(image);

    return 0;
}
