#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    ifstream inputFile("input.txt");

    int N, M;
    inputFile >> N >> M;

    // матрица А из нулей N x M
    vector<vector<int>> A(N, vector<int>(M));

    int minA = INT_MAX;
    int maxA = INT_MIN;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            inputFile >> A[i][j];
            minA = min(minA, A[i][j]);
            maxA = max(maxA, A[i][j]);
        }
    }

    // матрица В из нулей N x maxA + 1
    vector<vector<int>> B(N, vector<int>(maxA + 1));

    // Вычисление частотной матрицы
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            B[i][A[i][j]]++;
        }
    }

    ofstream outputFile("output.txt");

    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= maxA; j++) {
            outputFile << B[i][j] << " ";
        }
        outputFile << endl;
    }

    inputFile.close();
    outputFile.close();

    return 0;
}
