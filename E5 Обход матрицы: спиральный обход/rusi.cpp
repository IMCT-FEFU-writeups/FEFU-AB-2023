#include <iostream>
#include <fstream>

using namespace std;

int main() {
    short n, s = 0;
    ifstream input("input.txt");
    ofstream output("output.txt");
    input >> n;
    short m[n][n], x = 0, y = 0, rx = n, by = n, lx = 0, ty = 1;
    for (int i = 1; i < n * n + 1; i++) {
        m[y][x] =  i;
        switch (s) {
            case 0:
                x++;
                if ( x == rx - 1) {
                    s = 1;
                    rx -= 1;
                }
                break;
            case 1:
                y++;
                if ( y == by - 1) {
                    s = 2;
                    by -= 1;
                }
                break;
            case 2:
                x--;
                if ( x == lx) {
                    s = 3;
                    lx += 1;
                }
                break;
            case 3:
                y--;
                if ( y == ty) {
                    s = 0;
                    ty += 1;
                }
                break;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            output << m[i][j] << " ";
        }
        output << "\n";
    }
    return 0;
}
