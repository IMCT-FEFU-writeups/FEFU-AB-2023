/*
 * я пользовался способом рамки
 * у меня есть 
 * stop_h1 - h - horizontal, 1 - first
 * stop_v2 - v - vertical, 2 - end
 * и всё заполняется линиями, чередуясь
 */
#include <stdio.h>
#define max(a, b) (a > b ? a : b)

int main() {
    FILE *inp = fopen("input.txt", "r");
    FILE *out = fopen("output.txt", "w");
    int n, c = 1, now_i = 0, now_j = 0, some = 1;
    fscanf(inp, "%d", &n);
    int arr[n][n];
    int t = n/2+2;
    int stop_h1 = -1, stop_h2 = n, stop_v1 = -1, stop_v2 = n;
    while (--t) {
        while (now_j < stop_v2) {
            arr[now_i][now_j] = c;
            c++;
            now_j++;
        }
        now_j--;
        c--;
        stop_h1++;

        while (now_i < stop_h2) {
            arr[now_i][now_j] = c;
            c++;
            now_i++;
        }
        now_i--;
        c--;
        stop_v2--;

        while (now_j > stop_v1) {
            arr[now_i][now_j] = c;
            c++;
            now_j--;
        }
        now_j++;
        c--;
        stop_h2--;

        while (now_i > stop_h1) {
            arr[now_i][now_j] = c;
            c++;
            now_i--;
        }
        now_i++;
        c--;
        stop_v1++;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fprintf(out, "%d ", arr[i][j]);
        }
        fprintf(out, "\n");
    }

    fclose(inp);
    fclose(out);
    return 0;
}
