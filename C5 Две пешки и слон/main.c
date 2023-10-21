#include <stdio.h>
#define max(a, b) a > b? a: b
#define min(a, b) a < b? a: b

int main() {
    FILE* fin = fopen("input.txt", "r");
    FILE* fout = fopen("output.txt", "w+");
    int x1, y1, x2, y2;
    fscanf(fin, "%d %d %d %d", &x1, &y1, &x2, &y2);
    int min_x = min(x1, x2);
    int max_x = max(x1, x2);
    int k1_positive = y1 - x1;
    int k2_positive = y2 - x2;
    int k1_negative = y1 + x1;
    int k2_negative = y2 + x2;

    for (int x = min_x + 1; x < max_x; ++x) {
        if (x + k1_positive == x + k2_positive) {
            fprintf(fout, "%d %d\n", x, x + k1_positive);
            return 0;
        }
    }
    for (int x = min_x + 1; x < max_x; ++x) {
        if (-x + k1_negative == -x + k2_negative) {
            fprintf(fout, "%d %d\n", x, -x + k1_negative);
            return 0;
        }
    }

    for (int x = 0; x < 8; ++x) {
        if (-x + k1_negative == x + k2_positive && (x != x1 && x != x2) && ((x + k2_positive) > 0) &&
                (x + k2_positive <= 8)) {
            fprintf(fout, "%d %d\n", x, -x + k1_negative);
            return 0;
        }
        if (x + k1_positive == -x + k2_negative && (x != x1 && x != x2) && ((x + k1_positive) > 0) && 
                (x + k1_positive <= 8)) {
            fprintf(fout, "%d %d\n", x, x + k1_positive);
            return 0;
        }
    }
    fprintf(fout, "0");
    return 0;
}
