#include <stdio.h>

int main() {
    FILE *input, *output;
    input = fopen("input.txt", "r+");
    output = fopen("output.txt", "w+");

    long long int n, m, k, total_houses, needed_floor;

    fscanf(input, "%lld %lld %lld", &n, &m, &k);

    total_houses = n * m;

    if (k == 4 || k == 13) {
        fprintf(output, "-1");
        return 0;
    }
    if (k >= 14) {
        k -= 2;
    } else if (k >= 5) {
        k -= 1;
    }
    if (k > total_houses) {
        fprintf(output, "-1");
        return 0;
    } else {
        if (k % m != 0) {
            needed_floor = k / m + 1;
        } else {
            needed_floor = k / m;
        }
        if (needed_floor >= 12) {
            needed_floor += 2;
            fprintf(output, "%lld", needed_floor);
            return 0;
        } else if (needed_floor >= 4) {
            needed_floor += 1;
            fprintf(output, "%lld", needed_floor);
            return 0;
        } else {
            fprintf(output, "%lld", needed_floor);
            return 0;
        }
    }
}
