#include <iostream>
#include <fstream>

using namespace std;

string find(int m, int n, int lm = 0, int ln = 1, int rm = 1, int rn = 0) {
    if (m == lm + rm && n == ln + rn) return "";
    if (m * (ln + rn) < (lm + rm) * n) return 'L' + find(m, n, lm, ln, lm + rm, ln + rn);
    else return 'R' + find(m, n, lm + rm, ln + rn, rm, rn);
}

int main() {
    ifstream input("input.txt");
    ofstream output("output.txt");
    int m, n;
    input >> m >> n;
    output << find(m, n);
    output.close();
    return 0;
}
