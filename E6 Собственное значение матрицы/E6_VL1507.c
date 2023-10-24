// https://lms2.sseu.ru/courses/eresmat/course1/razd8z1/par8_18z1.htm
// для понимания задачи и решения

#include <stdio.h>

int main() {
    double a, b, c, l;
    char d;
    scanf("%lf %lf %lf %c %lf", &a, &b, &c, &d, &l);

    double numerator = a * l + c * b - l * l;
    double denominator = a - l;

    if (numerator == 0 && denominator == 0) {
        printf("INF");
    } else if (denominator == 0) {
        printf("NO");
    } else {
        printf("YES\n%.4lf", numerator / denominator);
    }
    return 0;
}
