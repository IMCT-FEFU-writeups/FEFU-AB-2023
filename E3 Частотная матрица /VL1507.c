#include <stdio.h>

void f(int max, int lenArrRow, int arrRow[lenArrRow]) {
    FILE *output = fopen("output.txt", "a");

    int arr[max + 1];

    for (int i = 0; i < max + 1; i++) {
        arr[i] = 0;
    }

    for (int i = 0; i < lenArrRow; i++) {
        arr[arrRow[i]]++;
    }

    for (int i = 0; i < max + 1; i++) {
        fprintf(output, "%d ", arr[i]);
    }
    fprintf(output, "\n");

    fclose(output);
}


int main() {
    FILE *input = fopen("input.txt", "r");

    int n, m;
    fscanf(input, "%d %d", &n, &m);

    int matrix[n][m], max = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            fscanf(input, "%d", &matrix[i][j]);
            max = (matrix[i][j] > max) ? matrix[i][j] : max;
        }
    }

    for (int i = 0; i < n; i++) {
        f(max, m, matrix[i]);
    }

    fclose(input);
    return 0;
}
