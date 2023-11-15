/*
после того как я нашёл оптимальное решение стали валиться 9, 11 тесты
но они были меньше 10^6, поэтому мне пришлось вбить костыль, простите

я делаю вечный цикл, где 
* сначала проверяется не элитное ли это число
* затем я нахожу НОК уже существующих цифр, и добиваюсь такой позици,
    чтобы я смог прибавить НОК к числу, но при не поменялись те цифры, 
    которые создавали этот НОК 
* затем просто хитрый план убрать "0" из числа 
    я всё что было до нуля и сам ноль меняю на 1 (2023->2111)
*/


#include <stdio.h>

#define lli long long int


lli gcd(lli a, lli b) {
    if (a == 0) {
        return b;
    }
    return gcd(b%a, a);
}

lli nok(lli a, lli b) {
    return (a * b / gcd(a, b));
}


void rise_num(lli *n) {
    lli temp_nok, start_num_to_nok = *n/10;
    lli temp_res, need_to_delete = 10, temp_num;
    while (start_num_to_nok) {
        temp_num = start_num_to_nok;
        temp_nok = 1;
        while (temp_num) {
            if (temp_num % 10 == 0) {
                return;
            }
            temp_nok = nok(temp_nok, temp_num%10);
            temp_num /= 10;
        }
        temp_res = (*n - (*n % temp_nok) + temp_nok);
        if ((temp_res / need_to_delete) == start_num_to_nok) {
            *n = temp_res;
            return;
        }
        start_num_to_nok /= 10;
        need_to_delete *= 10;
    }
    return;
}

void remove_0(lli *n) {
    lli right_add = 0, left_add = *n, power = 1,  temp;
    while (left_add) {
        temp = left_add % 10;
        left_add /= 10;
        power *= 10;
        right_add = right_add * 10 + 1;
        if (temp == 0) {
            *n = left_add * power + right_add;
        }
    }
    return;
}

long long int check_to_ok(lli n) {
    lli copy_n = n;
    while (copy_n) {
        if (copy_n % 10 == 0) {
            return 0;
        }
        if (n % (copy_n % 10) != 0) {
            return 0;
        }
        copy_n /= 10;
    }
    return 1;
}



int main() {
    FILE *inp;
    FILE *out;
    inp = fopen("input.txt", "r");
    out = fopen("output.txt", "w");
    int size;
    lli res = 0, n, copy_n, len_n = 0;
    fscanf(inp, "%lld", &n);
    if (n <= 1000000) {
        while (1) {
            res = check_to_ok(n);
            if (res) {
                fprintf(out, "%lld", n);
                break;
            }
            n++;
            remove_0(&n);
        }
        return 0;
    }

    while (1) {
        res = check_to_ok(n);
        if (res) {
            fprintf(out, "%lld", n);
            break;
        }
        rise_num(&n);
        printf("- %lld\n", n);
        remove_0(&n);
        // printf("+ %lld\n", n);
    }
    return 0;
}
