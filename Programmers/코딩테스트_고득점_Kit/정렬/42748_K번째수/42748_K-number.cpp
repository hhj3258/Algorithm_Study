#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands);

int main()
{
	vector<int> arr = { 1, 5, 2, 6, 3, 7, 4 };
	vector<vector<int>> commands = { {2, 5, 3},{4, 4, 1},{1, 7, 3} };

	solution(arr, commands);
}

//1: 시작 값 0
//2: 끝 값 1
// 정렬
//3: 출력 값 2

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
	vector<int> answer;

	for (int i = 0; i < commands.size(); i++) {	//반복 실행
		vector<int> temp;

		for (int k = commands[i][0] - 1; k < commands[i][1]; k++) {
			temp.push_back(array[k]);	//temp에 시작값~끝 값까지 입력 완료
		}

		sort(temp.begin(), temp.end());

		answer.push_back(temp[commands[i][2] - 1]);
	}

	return answer;
}