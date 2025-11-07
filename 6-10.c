#include <stdio.h>
#include <math.h>

int main() {
    int width = 500, height = 500;
    unsigned char* image = malloc(width*height);
    double k = 255.0;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            double x = (j - width/2) / (width/2.0);
            double y = (i - height/2) / (height/2.0);
            double value = k * fabs(sin(10*(x*x + y*y)));
            image[i*width + j] = (unsigned char)value;
        }
    }

    FILE* f = fopen("function.ppm", "wb");
    fprintf(f, "P5\n%d %d\n255\n", width, height);
    fwrite(image, 1, width*height, f);
    fclose(f);
    free(image);
    return 0;
}
