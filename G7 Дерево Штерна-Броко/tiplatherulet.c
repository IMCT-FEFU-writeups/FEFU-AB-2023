#include <stdio.h>

FILE *input, *output;
void path(int x, int y, int a, int b, int c, int d) {
    extern FILE *input, *output;

    int m = a + c;
    int n = b + d;
    if (x == m && y == n) {
        return;
    }
    if (x * n < y * m) {
        fprintf(output, "L");
        path(x, y, a, b, m, n);
    }
    else {
        fprintf(output, "R");
        path(x, y, m, n, c, d);
    }
}

int main() {
    extern FILE *input, *output;
    input = fopen("input.txt", "r+");
    output = fopen("output.txt", "w+");

    int a = 0;
    int b = 1;
    int c = 1;
    int d = 0;

    int x, y;

    fscanf(input, "%d %d", &x, &y);

    path(x, y, a, b, c, d);

    return 0;
}
