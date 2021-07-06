#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
string solution(vector<string> participant, vector<string> completion);

int main()
{
	vector<string> participant1 = { "leo", "kiki", "eden" };
	vector<string> completion1 = { "eden", "kiki" };

	vector<string> participant3 = { "mislav", "stanko", "mislav", "ana", "jona", "jona" };
	vector<string> completion3 = { "stanko", "ana", "jona", "mislav", "jona" };

	cout << "answer: " << solution(participant3, completion3);
}

string solution(vector<string> participant, vector<string> completion) {
	string answer = "";
	unordered_map<string, int> parti_map;
	unordered_map<string, int> com_map;

	for (string name : participant) {
		parti_map[name]++;
	}

	for (string name : completion) {
		com_map[name]++;
	}

	for (string name : participant) {
		if (parti_map[name] != com_map[name]) {
			answer = name;
			break;
		}
	}

	return answer;
}