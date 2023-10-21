/*
тут я даже не знаю что объяснять
читай условие 
считывай матрицу
проходи как надо
3 тест - это m = 1
*/
#include <stdio.h>
int main(){
    long long int n, m;
    scanf("%lld %lld", &n, &m);
    long long int mat[n][m];
    long long int res = 0;
    for (int i = 0;i < n;i++){
        for (int j = 0;j < m;j++){
            scanf("%lld", &mat[i][j]);
        }
    }
    for (int i = 0;i < n;i++){
        res += (mat[i][0] * mat[i][m-1]);
    }
    printf("%lld", res);
    
    return 0;
}
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




