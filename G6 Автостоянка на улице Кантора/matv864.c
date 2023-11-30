/*
объясняю это нечто
я представил всё в виде диагоналей, в которых элементы возрастают на +1
и по сути мне нужно сначала найти нужную диагональ
я смотрю на первую строку и пытаюсь найти место, где left <= x <= right
(((
    нахожу я это вот как
    каждый элемент первой строки это f(x) = ( n * (n + 1) ) / 2
    и через систему из 2 неравенств нахожу формулу
)))
а затем зная первый элемент диагонали и его координату высчитываю итоговые координаты

*/


#include <stdio.h>
#include <math.h>

typedef struct Coords Coords;
struct Coords{
    long long int x, y;
};


Coords get_coords(long long int x){
    Coords result;
    long long int n_left, n, x_left, t;
    n_left = (int)((sqrt(8 * x + 1) - 3)/2);
    n = floor(n_left);
    n++;
    x_left = (n * (n + 1)) / 2;
    t = x - x_left;
    
    result.x = n - t;
    result.y = t;
    return result;
}


int main(){
    FILE *inp = fopen("input.txt", "r");
    FILE *out = fopen("output.txt", "w");
    
    Coords result;
    
    
    long long int n, x;
    fscanf(inp, "%lld", &n);
    while(n--){
        fscanf(inp, "%lld", &x);
        result = get_coords(x);
        fprintf(out, "%lld %lld\n", result.x, result.y);
    }

    return 0;
}