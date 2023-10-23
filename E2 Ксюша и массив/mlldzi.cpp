#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int num;

    ifstream inputFile("input.txt");
    inputFile >> num;
    vector<int> numbers;

    for (int i = 0; i < num; i++) {
        int sub;
        inputFile >> sub;
        numbers.push_back(sub);
    }
    inputFile.close();

    sort(numbers.begin(), numbers.end());
    int result = -1;

    for (int element : numbers) {
        bool isDivisibleByAll = true;
        for (int second_element : numbers) {
            if (second_element % element != 0) {
                isDivisibleByAll = false;
                break;
            }
        }
        if (isDivisibleByAll) {
            result = element;
            break;
        }
    }

    ofstream outputFile("output.txt");
    outputFile << result;
    outputFile.close();
    return 0;
}
