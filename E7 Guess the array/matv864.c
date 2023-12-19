/*
задача не проверена, но открытые тесты верные
всё строится на том, что есть формула (a + b) % k = ((a % k) + (b % k)) % k
здесь я каждую сумму представлял так
и элементы a_i я держал (0 <= a_i < k)
(дальше сами)
*/
#include <stdio.h>
#define lli long long int
#define MAX_NUM 10000

int main() {
    lli n, k, sum;
    lli temp_now, all_sum = 0;
    lli need_plus_k;
    scanf("%lld %lld %lld", &n, &k, &sum);
    lli arr_a[n], arr_b[n];
    for (lli i = 0; i < n; i++) {
        scanf("%lld", &arr_b[i]);
    }
    temp_now = arr_a[0] = 0;
    for (lli i = 0; i < n - 1; i++) {
        if (temp_now <= arr_b[i]) {
            arr_a[i + 1] = (arr_b[i] - temp_now);
        } else {
            arr_a[i + 1] = (arr_b[i] + k - temp_now);
        }
        temp_now = arr_a[i + 1];
        all_sum += temp_now;
    }

    if ((arr_a[n - 1] != arr_b[n - 1]) || ((sum - all_sum) % k != 0)) {
        printf("NO");
        return 0;
    }
    need_plus_k = (sum - all_sum) / k;
    for (lli i = 0; i < n - 1; i++) {
        temp_now = MAX_NUM - arr_a[i];
        if ((temp_now / k) < need_plus_k) {
            need_plus_k -= (temp_now / k);
            arr_a[i] += (temp_now / k) * k;
        } else {
            if (need_plus_k == 0) {
                break;
            } else {
                arr_a[i] += need_plus_k * k;
                need_plus_k = 0;
            }
        }
    }
    printf("YES\n");
    for (lli i = 0; i < n; i++) {
        printf("%lld ", arr_a[i]);
    }
    return 0;
}
