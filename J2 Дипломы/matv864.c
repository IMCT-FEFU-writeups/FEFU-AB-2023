/*
одним из решений будет перебирать n - длину стороны доски
и проверять каждый n - можно ли всё положить на доску со стороной n

я сделал то же самое, но с бин поиском

(у меня почему-то не выводит в выходной файл, но возможно это глюк gdb)
*/



#include <stdio.h>

long long int a, b, n;

int check(long long int num) {
    if (((num / a) * (num / b)) >= n) {
        return 1;
    }
    return 0;
}


int main() {
    FILE *inp = fopen("diploma.in", "r");
    FILE *out = fopen("diploma.out", "w");
    fscanf(inp, "%lld %lld %lld", &a, &b, &n);
    long long int l = 0, r = a * n + b * n, m;
    while ((r - l) > 1) {
        m = (r + l) / 2;
        if (check(m)) {
            r = m;
        } else {
            l = m;
        }
    }
    // printf("%lld", r);
    fprintf(out, "%lld", r);
    fclose(inp);
    fclose(out);
    return 0;
}
