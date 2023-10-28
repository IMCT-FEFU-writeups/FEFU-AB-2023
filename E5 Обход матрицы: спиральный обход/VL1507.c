#include <stdio.h>

int main() {
    FILE *input = fopen("input.txt", "r");
    int n;
    fscanf(input, "%d", &n);
    fclose(input);

    int matrix[n][n], x = 0, y = 0;

    for (int i = 1; i < n * n + 1; i++) {
        matrix[y][x] = i;
        if ((y <= x + 1) && (x + y < n - 1)) {
            x++;
        } else if (y < x) {
            y++;
        } else if (x + y >= n) {
            x--;
        } else if (y >= x) {
            y--;
        }
    }

    FILE *output = fopen("output.txt", "w");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fprintf(output, "%d ", matrix[i][j]);
        }
        fprintf(output, "\n");
    }
    fclose(output);

    return 0;
}
