#include <iostream>
#include <fstream>
#include <string>
#include <set>

using namespace std;

int count_different_letters(string str) {
    set<char> letters;
    for (char ch : str) {
        letters.insert(ch);
    }
    return letters.size();
}

int main() {
    ifstream input("input.txt");
    ofstream output("output.txt");
    int n;
    char a;
    int b, c;
    string z = string(1000000, 'Z');
    input >> n;
    for (int i = 0; i < n; ++i) {
        input >> a >> b >> c;
        z.replace(b-1, (c - b) + 1, string((c - b) + 1, a));
    }
    output << count_different_letters(z);
    return 0;
}
