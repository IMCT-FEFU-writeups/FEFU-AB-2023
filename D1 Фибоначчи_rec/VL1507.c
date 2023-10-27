#include <stdio.h>

int fibonacci_rec(int n) {
    if (n == 0) { return 0; }
    if (n == 1 || n == 2) { return 1; }
    return fibonacci_rec(n - 1) + fibonacci_rec(n - 2);
}

int main() {
    FILE *input = fopen("input.txt", "r");
    int n;
    fscanf(input, "%d", &n);
    fclose(input);

    FILE *output = fopen("output.txt", "w");
    for (int i = 0; i < n; i++) {
        fprintf(output, "%d ", fibonacci_rec(i));
    }
    fclose(output);

    return 0;
}
