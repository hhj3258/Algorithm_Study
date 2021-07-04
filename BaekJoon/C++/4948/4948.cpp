#include <iostream>
using namespace std;

int main() {
	int n, no = 0;
	int x = 0;
	int arr[1000] = { 0, };
	int result[1000] = { 0, };

	while (true) {
		no = 0;
		cin >> no;

		if (no == 0) break;

		arr[x++] = no;
	}

	for (int y = 0; y < x; y++) {

		n = arr[y];
		int dob = 2 * n;
		bool boul[1000000] = { 0, };		//false

		for (int i = 2; i <= dob; i++) {
			int a = 0;

			if (i * i >= dob && n > 2) break;

			if (boul[i] == false) {
				for (int j = 2; a <= dob; j++) {
					a = i * j;
					boul[a] = true;
				}
			}
		}

		for (int i = n + 1; i <= dob; i++) {
			if (boul[i] == false)
				result[y]++;
		}
	}

	for (int i = 0; i < x; i++) {
		if (result[i] == 0) continue;
		cout << result[i] << endl;
	}

	return 0;
}