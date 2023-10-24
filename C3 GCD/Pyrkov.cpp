#include <iostream>

using namespace std;

int NOD(int a, int b) {
    while (a != 0 && b != 0) {
        if (a > b) {
            a = a % b;
        } else {
            b = b % a;
        }
    }
    return (a+b);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int a, b, c;
    cin >> a >> b >> c;
    cout << NOD(a, b) << ' ' << NOD(a, c) << ' ' << NOD(b, c);
}



