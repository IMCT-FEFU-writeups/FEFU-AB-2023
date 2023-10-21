#include <iostream>
#include <string>
#include <bitset>

using namespace std;

string bin(unsigned long long int n) {
    bitset<24> bin(n);
    return bin.to_string();
}

int main() {
    unsigned long long int n;
    string bn;
    char colour;
    cin >> n >> colour;
    bn = bin(n);
    if (colour == 'b') {
        cout << stoi(bn.substr(16, 8), 0, 2);
        return 0;
    }
    if (colour == 'g'){
        bn=bn.substr(8, 8)+"00000000";
        cout << stoll(bn, 0, 2);
        return 0;
    }
    if (colour == 'r'){
        bn=bn.substr(0, 8)+"0000000000000000";
        cout << stoull(bn, 0, 2);
        return 0;
    }
}
