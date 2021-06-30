#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations);

int main()
{
	vector<int> case1 = { 3, 0, 6, 1, 5 };
	vector<int> case2 = { 9, 7, 6, 2, 1 };
	vector<int> case3 = { 0,1,1 };
	vector<int> case4 = { 0,0,0 };
	vector<int> case5 = { 0,3 };


	cout <<"answer: "<< solution(case5);
}

int solution(vector<int> citations) {
	int answer = 0;

	sort(citations.begin(), citations.end());


	int h1 = citations[citations.size() - 1] + 1;
	vector<int> cnt(h1);

	//if (h1 == 0) {
	//	return answer;
	//}

	for (int i = 0; i < cnt.size(); i++) {
		for (int j = 0; j < citations.size(); j++) {
			if (i <= citations[j]) {
				cnt[i]++;
			}
		}
	}


	for (int i = cnt.size() - 1; i >= 0; i--) {
		cout << i << "번째: " << cnt[i] << endl;
	}
	cout << endl;

	for (int i = cnt.size() - 1; i >= 0; i--) {
		if (i == cnt[i]) {
			answer = cnt[i];
			cout << "chk" << endl;
			break;
		}
	}

	return answer;
}