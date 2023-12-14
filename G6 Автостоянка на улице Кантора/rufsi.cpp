#include <fstream>
#include <cmath>

using namespace std;

int main() {
    ifstream input("input.txt");
    ofstream output("output.txt");
    unsigned long long N, b, xn, n, x, y;
    input >> N;
    for (int i = 0; i < N; i++) {
        input >> b;
        n = (int)((sqrt(8 * b + 1) - 1) / 2);
        xn = (n * (n + 1)) / 2;
        y = b - xn;
        x = n - y;
        output << x << ' ' << y << '\n';
    }
    return 0;
}
