#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location);

int main()
{
	vector<int> priorities1 = { 2, 1, 3, 2 };   // 1 ~ 9
	int location1 = 2;      // 0 ~ priorities.size() -1

	vector<int> priorities2 = { 1, 1, 9, 1, 1, 1 };
	int location2 = 0;

	vector<int> priorities3 = { 1, 1, 9, 1, 1, 9 };
	int location3 = 5;

	vector<int> priorities4 = { 1, 1, 8, 1, 1, 9 };
	int location4 = 4;

	cout << "answer: " << solution(priorities3, location3);
}

int solution(vector<int> priorities, int location) {
	int answer = 1;

	int max_value = -1;
	int max_index = -1;

	do {
		max_value = *max_element(priorities.begin(), priorities.end());
		max_index = max_element(priorities.begin(), priorities.end()) - priorities.begin();

		for (int i = 0; i < max_index; i++) {
			priorities.push_back(priorities[0]);		 // 앞의 2개 원소를 큐에 다시 push
			priorities.erase(priorities.begin());		// push 한 만큼 pop

			if (location == 0) {
				location = priorities.size() - 1;
			}
			else {
				location--;
			}
		}

		if (location == 0 && max_value == priorities[0]) {
			break;
		}
		else {
			priorities.erase(priorities.begin());   // 대기열 1순위 pop
			answer++;
			location--;
		}

	} while (true);

	return answer;
}