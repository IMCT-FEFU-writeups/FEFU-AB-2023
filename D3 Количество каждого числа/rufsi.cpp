#include <iostream>
#include <fstream>

using namespace std;

void qsortRecursive(short *mas, int size) {
    int i = 0;
    int j = size - 1;
    int mid = mas[size / 2];
    do {
        while (mas[i] < mid) {
            i++;
        }
        while (mas[j] > mid) {
            j--;
        }
        if (i <= j) {
            short tmp = mas[i];
            mas[i] = mas[j];
            mas[j] = tmp;

            i++;
            j--;
        }
    } while (i <= j);
    if (j > 0) {
        qsortRecursive(mas, j + 1);
    }
    if (i < size) {
        qsortRecursive(&mas[i], size - i);
    }
}

int main() {
    int n;
    int unicc = 0;
    ifstream input("input.txt");
    ofstream output("output.txt");
    input >> n;
    short a[n];
    for (int i = 0; i < n; i++) {
        input >> a[i];
    }
    qsortRecursive(a, n);
    for (int i = 0; i < n; i++) {
        if (i != n - 1 && a[i] == a[i + 1]) {
            continue;
        }
        unicc++;

    }
    int c = 0;
    int b[unicc][2];
    for (int i = 0; i < n; i++) {
        if (i != n - 1 && a[i] == a[i + 1]) {
            continue;
        }
        b[c][0] = a[i];
        c++;
    }
    c = 0;
    int j = 0;
    for (int i = 0; i < unicc; i++) {
        cout << b[1][0] << " " << b[1][1] << "\n";
        for (; j < n + 1; j++) {
            if (b[i][0] == a[j]) {
                c++;
            } else {
                b[i][1] = c;
                c = 0;
                break;
            }
            if (j == n - 1) {
                b[i][1] = c;
                c = 0;
                break;
            }
        }
    }
    for (int i = 0; i < unicc; i++) {
        output << b[i][0] << " " << b[i][1] << endl;
    }
    return 0;
}
