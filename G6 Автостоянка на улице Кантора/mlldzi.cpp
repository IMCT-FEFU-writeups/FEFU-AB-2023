#include <fstream>
#include <cmath>
using namespace std;

pair<int, int> calculate_coordinates(int seat_number) {
    // ищу номер диагонали, на которой расположено искомое число
    int x = (int)((sqrt(8 * seat_number + 1) - 1)/2);
    // привожу к треугольному виду (1 -> 2, 2 -> 3, 3 -> 6, 4 -> 10 (это соответсвие номера треугольному числу))
    int tri_n = (x * (x + 1)) >> 1;
    int y = seat_number - tri_n;
    return make_pair(y, x - y);
}

int main() {
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");

    int n;
    inputFile >> n;

    for (int i = 0; i < n; ++i) {
        int seat_number;
        inputFile >> seat_number;
        pair<int, int> coordinates = calculate_coordinates(seat_number);
        outputFile << coordinates.second << " " << coordinates.first << "\n";
    }

    inputFile.close();
    outputFile.close();

    return 0;
}
