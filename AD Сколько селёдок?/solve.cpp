#include <iostream>
#include <cmath>

using namespace std;

int main() {
    long double wm, a = 0;
    long long int n;
    cin >> wm;
    n = (sqrt(8 * wm + 1) - 1) / 2;
    if (sqrt(wm * 8 + 1) == int(sqrt(wm * 8 + 1))) {
        cout << 1;
        return 0;
    }
    for (long long int i = n; i > 0; i--) {
        a = wm - (i * (i + 1) / 2);
        if (sqrt(a * 8 + 1) == int(sqrt(a * 8 + 1))) {
            cout << 2;
            return 0;
        }
    }
    cout << 3;
}
