/*
дополнительное решение без матрицы

*/

#include <stdio.h>
int main(){
    long long int n, m, first, last, trash, res = 0;
    scanf("%lld %lld", &n, &m);
    
    for (int i = 0;i < n;i++){
        scanf("%lld", &first);
        last = first; // на случай, когда m = 1
        for (int j = 0;j < m-1;j++){
            scanf("%lld", &last);
        }
        res += (first * last);
    }
    printf("%lld", res);
    
    return 0;
}
