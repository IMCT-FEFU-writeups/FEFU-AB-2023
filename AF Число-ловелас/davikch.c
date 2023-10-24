#include <stdio.h>

int main() {
    unsigned long long n;
    scanf("%llu", &n);
    for (int i = 0; i <= 64; i+= 4) {
        if ((n >> i) % (1 << 16) == 47806) { printf("YES"); return 0; }
        //  BABE = 1011 1010 1011 1110 = 47806
    }

    printf("NO");
    return 0;
}
