/*
 * спёр формулу отсюда
 * http://mathprofi.ru/sobstvennye_znachenija_i_sobstvennye_vektory.html
 * затем проверял на наличие 0/0 (в этом случае это даёт бесконечное множество решений)
 * проверял нет ли деления на ноль (понятно всем, что так нельзя)
 * и ответ
 */
#include <stdio.h>

#define ll long long int
#define ld long double

int main() {
    ld a, b, c, alph, up, down;
    char trash[1];
    scanf("%Lf %Lf %Lf", &a, &b, &c);
    scanf("%s", trash);
    scanf("%Lf", &alph);

    up = a * alph - alph * alph + b * c;
    down = a - alph;
    if ((down == 0) && (up == 0)) {
        printf("INF");
        return 0;
    }
    if (down == 0) {
        printf("NO");
        return 0;
    }
    printf("YES\n%.10Lf", (up / down));
    return 0;
}

