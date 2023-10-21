/*
здесь решение простое
просто перебор каждого элемента как делителя
и затем проверка является ли он делителем для всех элементов
(мне не нужно вставлять проверку на случай a % a, потому что a % a = 0)
*/
#include <stdio.h>
#define max(a,b) ((a>b?a:b))

int main(){
    FILE *inp;
    FILE *out;
    inp = fopen("input.txt", "r");
    out = fopen("output.txt", "w");
    long long int n, t, res=-1, del, c;
    fscanf(inp, "%lld", &n);
    long long int arr[n];
    for (int i = 0;i < n;i++){
        fscanf(inp, "%lld", &arr[i]);
    }
    for (int i = 0;i < n;i++){
        del = arr[i];
        c = 0;
        for (int j = 0;j < n;j++){
            if (arr[j] % del == 0){
                c++;
            }
            else{
                break;
            }
        }
        if (c == n){
            res = del;
          // можно вставить break, чтобы обрубать программу, когда хотя бы одно решение уже найдено
        }
    }
   
    fprintf(out, "%lld", res);
    fclose(inp);
    fclose(out);
    return 0;
}
