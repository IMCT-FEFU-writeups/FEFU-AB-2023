/*
что по коду
запускаю цикл, в конце каждой итерации я отрубаю по 4 бита (битовым сдвигом) или 1 16-ричное число
и также на каждой итерации проверяю 
беру 4 последних 16-ричных числа (по маске)
и сверяю с нужным
*/
#include <stdio.h>
#define ull unsigned long long int

int main() {
    ull n;
    scanf("%llu", &n);
    while (n > 0) {
        // printf("%llu\n", n&0xFFFF);
        if ((n&0xFFFF) == 0xBABE) {
            printf("YES");
            return 0;
        }
        n = n >> 4;
    }
    printf("NO");
    return 0;
}
