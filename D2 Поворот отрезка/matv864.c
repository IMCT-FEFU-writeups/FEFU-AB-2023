/*
что за херня тут творится? отвечаю
это решение с использованием полярных координат 
проще говоря
это координаты, где нет x y
там есть единственная ось
там все точки хранятся в виде (расстояние от центра до точки; и угол отклонения от оси)

(остальное чтиво можете найти сами)
код:
1) я преобразую угол поворота в радианы
2) я меняю оси (меняю точку начала системы координат, чтобы я мог крутить вокруг неё)
и попутно перевожу другие координаты в эту систему
3) перевожу всё в систему полярных координат (учитывая четверть угла)
4) угол каждой координаты я увеличиваю на угол поворота
5) перевожу в нашу обычную систему координат 
6) не забываю вернуть начало координат в точку (0, 0)
*/
#include <stdio.h>
#include <math.h>
#define ll long long int
#define ld long double
// sorry za moy bad angliyskiy)))
// radian * 180 / M_PI = degree

ld get_corner(ld dist, ld x, ld y) {
    if (x >= 0)
        return (asin(y / dist));
    else
        return (M_PI - (asin(y / dist)));
}

ld get_dist(ld x, ld y) {
    return sqrt(x * x + y * y);
}


int main() {
    FILE *inp;
    FILE *out;
    inp = fopen("input.txt", "r");
    out = fopen("output.txt", "w");
    ld x_a, y_a, x_b, y_b, x_o, y_o, rotate_degree, rotate_radian;
    ld pr_a, sin_alph_a, alph_a, pr_b, sin_alph_b, alph_b;
    fscanf(inp, "%Lf %Lf %Lf %Lf", &x_a, &y_a, &x_b, &y_b);
    fscanf(inp, "%Lf %Lf %Lf", &x_o, &y_o, &rotate_degree);
    rotate_radian = rotate_degree * M_PI / 180;
    // we make new system around new O
    x_a -= x_o;
    y_a -= y_o;
    x_b -= x_o;
    y_b -= y_o;
    // find polar coordinates (distance (pr_), degree (alph_))
    pr_a = get_dist(x_a, y_a);
    if (pr_a != 0) {
        alph_a = get_corner(pr_a, x_a, y_a);
        // rotate
        alph_a += rotate_radian;
        // return to decartoviy coordinates
        x_a = pr_a * cos(alph_a);
        y_a = pr_a * sin(alph_a);
    }
    // repeat
    // find polar coordinates (distance, degree)
    pr_b = get_dist(x_b, y_b);
    if (pr_b != 0) {
        alph_b = get_corner(pr_b, x_b, y_b);
        // rotate
        alph_b += rotate_radian;
        // return to decartoviy coordinates
        x_b = pr_b * cos(alph_b);
        y_b = pr_b * sin(alph_b);
    }
    // we return to old system O
    x_a += x_o;
    y_a += y_o;
    x_b += x_o;
    y_b += y_o;
    fprintf(out, "%.5Lf %.5Lf %.5Lf %.5Lf", x_a, y_a, x_b, y_b);
    fclose(inp);
    fclose(out);
    return 0;
}
