#include <iostream>
#include <fstream>

using namespace std;

int main() {
    int n, m, max = 0;
    ifstream input("input.txt");
    ofstream output("output.txt");
    input >> n >> m;
    int a[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            input >> a[i][j];
            max = (a[i][j] > max)? a[i][j]:max;
        }
    }
    int b[n][max+1], c;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < max+1; j++) {
            c = 0;
            for (int g = 0; g < m; g++) {
                c += (a[i][g] == j)? 1:0;
            }
            b[i][j] = c;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < max+1; j++) {
            output << b[i][j] << " ";
        }
        output << "\n";
    }
}
