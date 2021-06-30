#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations);

int main()
{
	vector<int> case1 = { 3, 0, 6, 1, 5 };	//3
	vector<int> case2 = { 9, 7, 6, 2, 1 };	//3
	vector<int> case3 = { 0,1,1 };			//1
	vector<int> case4 = { 0,0,0 };			//0
	vector<int> case5 = { 0,3 };				//1
	vector<int> case6 = { 0,2,2,2,5,5 };	//2


	cout << "answer: " << solution(case1) << endl;
	cout << "answer: " << solution(case2) << endl;
	cout << "answer: " << solution(case3) << endl;
	cout << "answer: " << solution(case4) << endl;
}

int solution(vector<int> citations) {
	int answer = 0;

	sort(citations.begin(), citations.end());

	int h1 = citations[citations.size() - 1];
	int h2 = citations.size() - 1;
	int cnt = 0;

	for (int i = h1; i > 0; i--) {
		for (int j = h2; j >= 0; j--) {
			if (i <= citations[j]) {
				cnt++;
			}
		}

		if (i == cnt) {
			answer = i;
			break;
		}
		else if (i < cnt) {
			answer = i;
			break;
		}

		cnt = 0;
	}

	return answer;
}