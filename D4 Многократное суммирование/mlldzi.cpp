#include <fstream>
#include <iostream>
#include <vector>

// префиксные суммы 

using namespace std;

int main() {
    long long N, M;

    ifstream inputFile("input.txt");
    inputFile >> N;

    vector<long long> sums_of_nums;
    for (int i = 0; i < N; i++) {
        long long sub;
        inputFile >> sub;
        if (i != 0) sums_of_nums.push_back(sums_of_nums[i - 1] + sub);
        else sums_of_nums.push_back(sub);
    }

    ofstream outputFile("output.txt");
    inputFile >> M;
    long left, right;
    for (int i = 0; i < M; i++) {
        inputFile >> left >> right;
        if (left == 1) outputFile << sums_of_nums[right - 1] << " ";
        else outputFile << sums_of_nums[right - 1] - sums_of_nums[left - 2] << " ";
    }

    inputFile.close();
    outputFile.close();
    return 0;
}
