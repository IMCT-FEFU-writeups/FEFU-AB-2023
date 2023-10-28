#include <stdio.h>

int main() {
    FILE *input = fopen("input.txt", "r");
    int n, max;
    fscanf(input, "%d", &n);
    fscanf(input, "%d", &max);
    for (int i = 0; i < n - 1; i++) {
        int num;
        fscanf(input, "%d", &num);
        if (num > max) { max = num; }
    }
    fclose(input);

    FILE *output = fopen("output.txt", "w");
    fprintf(output, "%d", max);
    fclose(output);
    return 0;
}
