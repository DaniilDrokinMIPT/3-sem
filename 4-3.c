#include <stdio.h>

void cube(float* px) {
    *px = *px * *px * *px;
}

int main() {
    float x = 2.0;
    cube(&x);
    printf("%.2f\n", x);
    return 0;
}
