#include <stdio.h>

int main() {
    FILE *in, *out;
    long long int n, m, k, flats_floor;
    in = fopen("input.txt", "r+");
    out = fopen("output.txt", "w+");
    fscanf(in, "%lld %lld %lld", &n, &m, &k);
    if (k == 4 || k == 13) {
        fprintf(out, "-1");
        return 0;
    }
    if (k > 4)
        --k;
    if (k > 12) /* 13-1 */
        --k;
    if (k > n * m) {
        fprintf(out, "-1");
        return 0;
    }
    if (k % m)
        flats_floor = k / m + 1;
    else
        flats_floor = k / m;
    /*
     * Fixing numbers that was broken by counting as normal
     */
    if (flats_floor >= 4)
        ++flats_floor;
    if (flats_floor >= 14) /* 13 + 1 */
        ++flats_floor;
    fprintf(out, "%lld", flats_floor);
}
