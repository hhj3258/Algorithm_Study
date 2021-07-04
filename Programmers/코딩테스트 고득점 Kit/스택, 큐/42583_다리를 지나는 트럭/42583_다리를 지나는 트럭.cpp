#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights);

int main()
{
	int bridge_length1 = 2;
	int weight1 = 10;
	vector<int> truck_weights1 = { 7,4,5,6 };

	int bridge_length2 = 100;
	int weight2 = 100;
	vector<int> truck_weights2 = { 10 };

	int bridge_length3 = 100;
	int weight3 = 100;
	vector<int> truck_weights3 = { 10,10,10,10,10,10,10,10,10,10 };

	//cout << "answer: " << solution(bridge_length1, weight1, truck_weights1);
	//cout << "answer: " << solution(bridge_length2, weight2, truck_weights2);
	cout << "answer: " << solution(bridge_length3, weight3, truck_weights3);
}

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int answer = 0;

	vector<int> now_weight;
	int sum_weight = 0;
	int increase_len = bridge_length;
	queue<int> finish_time;

	for (int i = 1; ; i++) {		// i = 시간(초)

		if (i > 1) {
			if (i == finish_time.front()) {
				sum_weight -= now_weight[0];
				now_weight.erase(now_weight.begin());
				finish_time.pop();
			}
		}

		if (now_weight.size() == 0 && truck_weights.size() == 0) {
			answer = i;
			break;
		}

		if (truck_weights.size() > 0) {
			if (sum_weight + truck_weights[0] <= weight) {
				sum_weight += truck_weights[0];
				now_weight.push_back(truck_weights[0]);
				truck_weights.erase(truck_weights.begin());

				finish_time.push(bridge_length + i);
			}
		}

	}

	return answer;
}