// можете что-то про префиксные суммы погуглить

/*
    Пример:
Вводится 1 2 3 4 5. Тогда arr = {1, 3, 6, 10, 15}
Надо вывести 1 3 => arr[end - 1] = arr[3 - 1] = arr[2] = 6
Надо вывести 2 5 => arr[end - 1] - arr[start - 2] = 15 - 1 = 14
*/

#include <stdio.h>

int main() {

    FILE *input = fopen("input.txt", "r");
    FILE *output = fopen("output.txt", "w");

    int n;
    fscanf(input, "%d", &n);

    int arr[n];
    fscanf(input, "%d", &arr[0]);
    for (int i = 1; i < n; i++) {
        int num;
        fscanf(input, "%d", &num);
        arr[i] = arr[i - 1] + num;
    }

    int m;
    fscanf(input, "%d", &m);

    for (int i = 0; i < m; i++) {
        int start, end;
        fscanf(input, "%d %d", &start, &end);
        if (start == 1) {
            fprintf(output, "%d ", arr[end - 1]);
        } else {
            fprintf(output, "%d ", arr[end - 1] - arr[start - 2]);
        }
    }

    fclose(input);
    fclose(output);

    return 0;
}
