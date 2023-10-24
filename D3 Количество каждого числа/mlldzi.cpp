#include <fstream>
#include <iostream>
#include <map>
#include <set>

/* 
  создаю словварь: ключ - число, значение - кол-во
  добавляю в множество числа, из-за того что множество не нужно сортировать и проверять на дубликаты
  по элементу множества получааю значение из словаря
*/
using namespace std;

int main() {
    unsigned int N;
    set<int> numbers;
    map<int, int> count_of_nums;

    ifstream inputFile("input.txt");
    inputFile >> N;
    for (int i = 0; i < N; i++) {
        int sub;
        inputFile >> sub;
        numbers.insert(sub);
        count_of_nums[sub]++;
    }
    inputFile.close();

    ofstream outputFile("output.txt");
    for (int elem: numbers) {
        outputFile << elem << " " << count_of_nums[elem] << endl;
    }
    outputFile.close();
    return 0;
}
