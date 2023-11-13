/*

в общем 
это дерево где на каждом этаже я нахожу середину
и смотрю в левую или в правую сторону пойдёт заданная дробь
и на каждом этапе я перезаписываю этаж дерева, на котором нахожусь
на данной итерации
и рано или поздно середина этажа станет этой дробью  

*/

#include <stdio.h>
#define lli long long int



struct drob{
    lli up;
    lli down;
};

struct floor_tree{
    struct drob right;
    struct drob middle;
    struct drob left;
};


lli gcd(lli a, lli b) {
    if (a == 0) {
        return b;
    }
    return gcd(b%a, a);
}
lli nod(lli a, lli b) {
    return a * b / gcd(a, b);
}

int cmp_drob(struct drob a, struct drob b) {
    lli common_down = nod(a.down, b.down);
    lli new_a = a.up * (common_down / a.down);
    lli new_b = b.up * (common_down / b.down);
    return (new_a >= new_b);
}
// 1 if a >= b else 0
int find_in_floor_tree(struct floor_tree temp_tree, struct drob this) {
    return cmp_drob(this, temp_tree.middle);
}
// 0 if l < this < m
// 1 if m < this < r







int main() {
    FILE *inp;
    FILE *out;
    inp = fopen("input.txt", "r");
    out = fopen("output.txt", "w");
    struct drob r = {0, 1}, m = {1, 1}, l = {1, 0}, new_middle = {-1, -1};
    struct floor_tree temp_tree = {r, m, l};
    lli up, down;
    fscanf(inp, "%lld %lld", &up, &down);
    struct drob new_drob = {up, down};
    while(1) {
        if (find_in_floor_tree(temp_tree, new_drob)) {
            new_middle.up = temp_tree.middle.up+temp_tree.left.up;
            new_middle.down = temp_tree.middle.down+temp_tree.left.down;
            temp_tree.right = temp_tree.middle;
            temp_tree.middle = new_middle;
            temp_tree.left = temp_tree.left;
            fprintf(out, "R");
            if ((new_middle.up == new_drob.up) && (new_middle.down == new_drob.down)) {
                return 0;
            }
        }
        else {
            new_middle.up = temp_tree.middle.up+temp_tree.right.up;
            new_middle.down = temp_tree.middle.down+temp_tree.right.down;
            temp_tree.right = temp_tree.right;
            temp_tree.left = temp_tree.middle;
            temp_tree.middle = new_middle;
            fprintf(out, "L");
            if ((new_middle.up == new_drob.up) && (new_middle.down == new_drob.down)) {
                return 0;
            }
        }
    }
    return 0;
}