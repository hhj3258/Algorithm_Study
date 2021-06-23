#include <iostream>
using namespace std;

int main(void) {

	int sum = 0;
	string ex;

	cin >> ex;

	for (int i = 0; i < ex.length(); i++) {
		if (i < ex.length() - 1) {
			if (i < ex.length() - 2) {
				string aaa = "";
				for (int k = i; k < i + 3; k++)
					aaa += ex.at(k);

				if (aaa == "dz=") {
					sum++;
					i += 2;
					continue;
				}
			}

			if ('=' == ex.at(i + 1)) {
				if (ex.at(i) == 'c' || ex.at(i) == 's' || ex.at(i) == 'z') {
					sum++;
					i += 1;
				}
				else
					sum++;
			}
			else if ('j' == ex.at(i + 1)) {
				if (ex.at(i) == 'l' || ex.at(i) == 'n') {
					sum++;
					i += 1;
				}
				else
					sum++;
			}
			else if ('-' == ex.at(i + 1)) {
				if (ex.at(i) == 'c' || ex.at(i) == 'd') {
					sum++;
					i += 1;
				}
				else
					sum++;
			}
			else
				sum++;
		}
		else
			sum++;
	}

	cout << sum;

	return 0;
}