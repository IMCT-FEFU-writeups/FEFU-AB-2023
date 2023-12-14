/*
в чём суть 
с помощью бинарного поиска мы перебираем возможный платёж
и для каждой суммы платежа мы модулируем ситуацию с таким платежом
(но самый главный прикол, уследить за переполнением credit потому что при маленьких платежах
credit улетает до небес а потом становится маленьким значением и выдаёт ошибочный результат)
(поэтому я смотрю, чтобы кредит не повышался, 
если он повысится он постоянно будет подниматься и расплатиться чел не сможет, 
поэтому при такой ситуации я сразу возвращаю, что чел не погасит)
*/
#include <stdio.h>
#include <math.h>

long long int n, p, c;

int check(long long int num) {
    long long int month = 0;
    long long int adding, credit = c, last_credit = c;
    long double temp;
    // printf("--%d %lld %lld\n", month, credit, num);
    while (month < 12 * n) {
        credit -= num;
        if (credit <= 0) {
            return 1;
        }
        temp = credit * p;
        temp /= 100;
        // printf("=%Lf--\n", temp);
        adding = ceil(temp);
        credit += adding;
        if (credit > last_credit) {
            return 0;
        } else {
            last_credit = credit;
        }
        month++;
        // printf("%d %lld %lld\n", month, credit, adding);
    }
    return (credit <= 0);
}


int main() {
    FILE *inp = fopen("input.txt", "r");
    FILE *out = fopen("output.txt", "w");
    fscanf(inp, "%lld %lld %lld", &n, &p, &c);
    long long int l = 0, r = c, m;
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
