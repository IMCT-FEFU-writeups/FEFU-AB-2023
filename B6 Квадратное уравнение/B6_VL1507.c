#include <stdio.h>
#include <math.h>

int main() {
    FILE *input = fopen("input.txt", "r");
    double a, b, c;
    fscanf(input, "%lf %lf %lf", &a, &b, &c);
    fclose(input);

    double d = b * b - 4 * a * c;
    FILE *output = fopen("output.txt", "w");
    
    if (a == 0 && b == 0) {
        fprintf(output, "-1");
    }
    else if (a == 0) {
        double x = -c / b;
        fprintf(output, "%.4lf %.4lf", x, x);
    }
    else if (d >= 0) {
        double x1 = (-b + pow(d, 0.5)) / (2 * a);
        double x2 = (-b - pow(d, 0.5)) / (2 * a);
        fprintf(output, "%.4lf %.4lf", x1, x2);
    }
    else {
        fprintf(output, "-1");
    }
    
    fclose(output);
    
    return 0;
}
