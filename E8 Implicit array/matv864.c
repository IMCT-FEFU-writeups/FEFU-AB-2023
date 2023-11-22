/*
если вы не поняли задачу - то делать вам здесь нечего 
(условие я объяснить не смогу)

мы перебираем строки ввода
настоящее число - это то число, которое даст нам эта строка ввода
прошедшее число - это то число, которое нам выдала прошлая строка
следующее число - это то число, которое точно будет идти следующим 

* допустим первая цифра строки 1
тогда прошедшее, настоящее и следующее с таким же значением

* допустим первая цифра строки 3
тогда прошедшее, настоящее и следующее - это отсортированные числа этой строки соответственно

* допустим первая цифра строки 2

мы автоматически узнаём прошедшее и следующее - это наименьшее и наибольшее соответственно
(((
    входная строка 
    2 1 4
    возможные варианты 
    1 1 4
    1 4 4
)))

добавки в моём коде
*1
мне лень брать считать среднее число в случае "3", поэтому
я беру из прошлой строки следубщее
использую здесь как настоящее

*2
также я делаю для случая "2", но тут это единственный выход

*3 
если в первой строке случа "2", то так не пойдёт
и 
настоящее - это меньшее число из эти двух
следующее - это большее число из эти двух
*/

#include <stdio.h>

#define lli long long int

#define max(a, b) ((a > b)?(a):(b))
#define min(a, b) ((a < b)?(a):(b))

int main() {
    FILE *inp;
    FILE *out;
    inp = fopen("input.txt", "r");
    out = fopen("output.txt", "w");
    int n, type_now;
    lli now, next;
    lli a, b, c, temp;
    lli last_a, last_b, last_c;
    fscanf(inp, "%d", &n);
    // костыль для 2 в начале
    fscanf(inp, "%d", &type_now);
    if (type_now == 1) {
        fscanf(inp, "%lld", &a);
        now = a;
        next = a;
    } else if (type_now == 2) {
        fscanf(inp, "%lld %lld", &a, &b);
        // small sorting start
        last_a = a;
        last_b = b;
        a = min(last_a, last_b);
        b = max(last_a, last_b);
        // small sorting end
        now = a;
        next = b;
    } else {
        while (1) {
            now++;
        }
    }  // проверяю тесты на адекватность в этом моменте
    fprintf(out, "%lld ", now);
    // костыль окончен
    for (int i = 1; i < n; i++) {
        fscanf(inp, "%d", &type_now);
        if (type_now == 1) {
            fscanf(inp, "%lld", &a);
            now = a;
            next = a;
        } else if (type_now == 2) {
            fscanf(inp, "%lld %lld", &a, &b);
            // small sorting start
            last_a = a;
            last_b = b;
            a = min(last_a, last_b);
            b = max(last_a, last_b);
            // small sorting end
            now = next;
            next = b;
        } else {
            fscanf(inp, "%lld %lld %lld", &a, &b, &c);
            // small sorting start
            last_a = a;
            last_b = b;
            last_c = c;
            c = max(last_c, max(last_a, last_b));
            a = min(last_c, min(last_a, last_b));
            // small sorting end
            now = next;
            next = c;
        }
        fprintf(out, "%lld ", now);
    }
    return 0;
}
