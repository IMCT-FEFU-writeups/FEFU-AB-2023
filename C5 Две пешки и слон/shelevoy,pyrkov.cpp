#include <iostream>

using namespace std;

int main() {
    int x1, y1, x2, y2, xa, ya;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> x1 >> y1 >> x2 >> y2;

    if (!(((x1 + y1) % 2) == ((x2 + y2) % 2))) {
        cout << 0;
        return 0;
    }
    if (abs(x1 - x2) == abs(y2 - y1)) {
        if (abs(x2 - x1) > 1 && abs(y2 - y1) > 1) {
            if (x2 > x1 and y2 > y1) {
                cout << x1 + 1 << ' ' << y1 + 1;
                return 0;
            }
            if (x2 > x1 and y2 < y1) {
                cout << x1 + 1 << ' ' << y1 - 1;
                return 0;
            }
            if (x2 < x1 and y2 > y1) {
                cout << x2 + 1 << ' ' << y2 - 1;
                return 0;
            } else {
                cout << x2 + 1 << ' ' << y2 + 1;
                return 0;
            }
            return 0;
        } else {
            cout << 0;
            return 0;
        }
    }
    for (int y = 1; y < 9; y++) {
        for (int x = 1 + (x1 + y1 + y - 1) % 2; x < 9; x += 2) {
            if ((x == x1 && y == y1) || (x == x2 && y == y2)) {
                continue;
            }
            if ((abs(x - x2) == abs(y - y2)) && (abs(x1 - x) == abs(y1 - y))) {
                cout << x << ' ' << y;
                return 0;
            }

        }
    }
}
