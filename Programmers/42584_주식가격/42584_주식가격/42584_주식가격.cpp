#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices);

int main()
{
	vector<int> prices1 = { 1, 2, 3, 2, 3 };
	vector<int> prices2 = { 5,4,5,2,5 };

	vector<int> answer = solution(prices2);

	cout << "answer: ";
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << " ";
	}
}

vector<int> solution(vector<int> prices) {
	vector<int> answer(prices.size());

	int price_temp = 0;
	for (int i = 0; i < prices.size(); i++) {
		price_temp = prices[i];

		for (int j = i; j < prices.size() - 1; j++) {
			if (prices[j + 1] >= price_temp) {  //price의 다음 원소가 현재 temp 원소보다 크다면 1초 증가
				answer[i] += 1;
			}
			else if (prices[j + 1] < price_temp) {
				answer[i] += 1;
				break;
			}
		}

	}

	return answer;
}