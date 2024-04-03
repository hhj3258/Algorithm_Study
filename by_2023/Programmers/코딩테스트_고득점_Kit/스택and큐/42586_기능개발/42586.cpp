#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds);

int main() {
	//입력 배열은 100개 이하
	vector<int> progresses1 = { 93,30,55 };		//100 미만의 자연수
	vector<int> speeds1 = { 1,30,5 };				//100 이하의 자연수

	vector<int> progresses2 = { 95, 90, 99, 99, 80, 99 };
	vector<int> speeds2 = { 1, 1, 1, 1, 1, 1 };


	vector<int> sol=solution(progresses1, speeds1);

	for (int i = 0; i < sol.size(); i++) {
		cout << i + 1 << "일 째: " << sol[i] << endl;
	}
}

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;

	int finish = 0;
	int cnt = 0;

	do {
		for (int j = finish; j < progresses.size(); j++) {
			progresses[j] += speeds[j];

			if (progresses[finish] >= 100) {
				cnt++;
				finish++;
			}
		}

		if (cnt != 0) {
			answer.push_back(cnt);
			cnt = 0;
		}

	} while (finish != progresses.size());

	return answer;
}