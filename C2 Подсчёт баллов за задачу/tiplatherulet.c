#include <stdio.h>

int main() {
    int n, sum = 0;
    char c;

    FILE *input, *output;
    input = fopen("input.txt", "r+");
    output = fopen("output.txt", "w+");

    fscanf(input, "%d", &n);

    int а[n];

    for (int i = 0; i < n; i++) {
        fscanf(input, "%d", &a[i]);
    }
    for (int i = 0; i < n; i++) {
        fscanf(input, " %c", &c);
        if (c == '+') {
            sum += a[i];
        }
    }

    fprintf(output, "%d", sum);
    return 0;
}
