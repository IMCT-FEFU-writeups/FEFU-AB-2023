#include <iostream>
#include <cmath>
using namespace std;

int main() {

	long long vmassa, minseledmassa, maxseledmassa, nextseled, sumseled, answer;
	long double num;
	int flag = 1;
	cin >> vmassa;
	num = floor((sqrt(1 + 8 * vmassa) - 1) / 2);
	for (long long n = 1; minseledmassa <= vmassa; n++) {
		minseledmassa = (n * n + n) / 2;
		nextseled = minseledmassa;
		if (minseledmassa == vmassa) {
			answer = 1;
			flag = 0;
			break;
		}

		if (vmassa < 65000000) {
			for (long long k = n; minseledmassa + nextseled <= vmassa; k++) {
				sumseled = minseledmassa + nextseled;
				if (sumseled == vmassa) {
					answer = 2;
					flag = 0;
					break;
				}
				else {
					nextseled = (k * k + k) / 2;
				}
			}
		}
		else {
			maxseledmassa = (num * num + num) / 2;
			if (maxseledmassa + minseledmassa == vmassa) {
				answer = 2;
				flag = 0;
				break;
			}
			else if (maxseledmassa + minseledmassa > vmassa) {
				num = num - 1;
				if (maxseledmassa + minseledmassa == vmassa) {
					answer = 2;
					flag = 0;
					break;
				}
			}
		}
	}
	if (flag == 1) {
		cout << 3;
	}
	else {
		cout << answer;
	}
}
