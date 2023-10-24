#include <stdio.h>

int gcd(int x, int y) {    /*Google le Euclidean algorithm*/
    while (x != 0 && y != 0) {
        if (x > y)
            x = x % y;
        else
            y = y % x;
    }
    return x + y;
}

int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    printf("%d %d %d", gcd(a, b), gcd(a, c), gcd(b, c));
    return 0;
}
