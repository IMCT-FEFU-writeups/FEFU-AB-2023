#include <fstream>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

// помещаю в стек индексы чисел, если нахожу большее, то меняю числа в стеке в глубь, сравнивая каждое "более глубокое" с новым большим 

vector<long long int> findNextGreater(vector<long long int> nums) {
    int N = nums.size();
    vector<long long int> result(N);

    for (int i = 0; i < N; ++i) {
        result[i] = nums[i];
    }

    stack<int> st;

    for (int i = 0; i < N; ++i) {
        while (!st.empty() && nums[i] > nums[st.top()]) {
            result[st.top()] = nums[i]; 
            st.pop(); 
        }
        st.push(i);
    }

    return result;
}

int main() {
    ifstream inputFile("input.txt");
    long int N;
    inputFile >> N;
    vector<long long int> nums(N);
    for (int i = 0; i < N; ++i) {
        inputFile >> nums[i];
    }
    inputFile.close();

    vector<long long int> result = findNextGreater(nums);

    ofstream outputFile("output.txt");
    for (int i = 0; i < N; ++i) {
        outputFile << result[i] << " ";
    }
    outputFile.close();

    return 0;
}
