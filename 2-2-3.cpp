#include <stdio.h>

float yearfrac(int year, int day) {
    int days_in_year = (year % 4 == 0) ? 366 : 365;
    return (float)day / days_in_year;
}

int main() {
    int year, day;
    scanf("%i %i", &year, &day);
    printf("%.5f\n", yearfrac(year, day));
    return 0;
}
