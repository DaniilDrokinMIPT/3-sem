#include <stdio.h>
#include <math.h>

int main() {
    double x1, y1, r1, x2, y2, r2;
    scanf("%lf %lf %lf", &x1, &y1, &r1);
    scanf("%lf %lf %lf", &x2, &y2, &r2);

    double dx = x2 - x1;
    double dy = y2 - y1;
    double d = sqrt(dx*dx + dy*dy);
    double sum_r = r1 + r2;
    double diff_r = fabs(r1 - r2);
    const double eps = 1e-5;

    if (d > sum_r + eps)
        printf("Do not intersect\n");
    else if (d < diff_r - eps)
        printf("Do not intersect\n");
    else if (fabs(d - sum_r) < eps || fabs(d - diff_r) < eps)
        printf("Touch\n");
    else
        printf("Intersect\n");

    return 0;
}
