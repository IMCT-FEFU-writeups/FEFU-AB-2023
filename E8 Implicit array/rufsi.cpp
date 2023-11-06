#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ifstream input("input.txt");
    ofstream output("output.txt");
    int N;
    input >> N;
    int n, arr[N], b, c, a, d;
    for (int i = 0; i < N; ++i) {
        n = 0;
        input >> n;
        if (n == 1) {
            input >> b;
            arr[i] = b;
            c = b;
            b = 0;
        } else if (n == 3) {
            int g[3];
            input >> g[0] >> g[1] >> g[2];
            sort(g, g + 3);
            arr[i] = g[1];
        } else {
            input >> a >> b;
            if (a > b) {
                d = b;
                b = a;
                a = d;
                d = 0;
            }
            if (i == N-1){
                arr[i] = b;
                break;
            }
            if (c == a || i == 0) {
                arr[i] = a;
                c = 0;
            } else {
                arr[i] = b;
                c = b;
            }
            b = 0;
            a = 0;
        }
    }
    for (int i : arr) {
        output << i << " ";
    }
}
