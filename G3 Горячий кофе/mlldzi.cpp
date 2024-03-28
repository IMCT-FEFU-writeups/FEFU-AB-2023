#include <fstream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

// Симулирую очередь за кофе с каждым параметром t от 1 до максимального времени прибытия, и ищу t, при котором происходит смена очереди на p
// использую бин поиск, потому что тл и мл, если симулировать прям для каждого

int simulate_queue(int n, int k, int p, const vector<int>& visitors) {
    int last = -k;
    deque<int> dequ;
    int max_length = 0;

    int i = 0;
    while (i < visitors.size()) {
        int visitor = visitors[i];

        if (!dequ.empty()) {
            while (!dequ.empty() && visitor >= k + last) {
                last += k;
                dequ.pop_front();
            }
        }

        if (visitor >= k + last) last = visitor;
        else dequ.push_back(visitor);

        max_length = max(static_cast<int>(dequ.size()), max_length);
        if (max_length == p) break; // если мы дошли до p, то нет смысла искать дальше тк это не удовл условию задачи
        i++;
    }

    return max_length;
}

int binary_search(int n, int p, const vector<int>& arrival_times) {
    int left = 1;
    int right = arrival_times.back() + 1;

    while (left < right) {
        int mid = (left + right) / 2;
        if (simulate_queue(n, mid, p, arrival_times) >= p) right = mid;
        else left = mid + 1;
    }

    return left - 1;
}

int main() {
    ifstream file("input.txt");
    int n, p;
    file >> n >> p;
    vector<int> arrival_times(n);
    for (int i = 0; i < n; i++) {
        file >> arrival_times[i];
    }
    file.close();

    sort(arrival_times.begin(), arrival_times.end());

    int ans = binary_search(n, p, arrival_times);

    ofstream output("output.txt");
    output << ans;
    output.close();

    return 0;
}
