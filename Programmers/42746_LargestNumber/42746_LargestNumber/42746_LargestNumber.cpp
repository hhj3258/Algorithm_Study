#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<int> numbers);

int main()
{
	vector<int> numbers = { 6,10,2 };

	cout << solution(numbers);
}

bool Compare(const vector<int>& v1, const vector<int>& v2)
{
	return v1[1] > v2[1];
}

string solution(vector<int> numbers) {
	string answer = "";

	vector<vector<int>> temp(numbers.size(), vector<int>(2, 0));

	for (int i = 0; i < temp.size(); i++) {
		temp[i][1] = numbers[i];

		while (temp[i][1] < 1000 && temp[i][1] > 0) { // 각 원소가 1000보다 커질 때까지 * 10
			temp[i][0]++;       // 0을 몇 개 붙였는지 카운트
			temp[i][1] = temp[i][1] * 10;
		}

		if (temp[i][0] == 1) {
			temp[i][1] += numbers[i] / 100;
		}
		else if (temp[i][0] == 2) {
			temp[i][1] += numbers[i];
		}
		else if (temp[i][0] == 3) {
			temp[i][1] += numbers[i];
			temp[i][1] += numbers[i] * 10;
			temp[i][1] += numbers[i] * 100;
		}

	}

	sort(temp.begin(), temp.end(), Compare);	// 두번째 열 기준 내림차순 정렬

	for (int i = 0; i < temp.size(); i++) { //3
		while (temp[i][0] > 0) {
			temp[i][0]--;
			temp[i][1] = temp[i][1] / 10;
		}

		answer += to_string(temp[i][1]);    //문자열로 변환 후 합침
	}

	if (answer[0] == '0') answer = "0";		//입력 값이 모두 0이라면 "0"

	return answer;
}
