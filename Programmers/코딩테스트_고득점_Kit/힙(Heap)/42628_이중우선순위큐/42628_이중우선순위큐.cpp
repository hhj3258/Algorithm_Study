#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> operations)
{
    vector<int> answer(2);
    priority_queue<int, vector<int>, greater<>> min_q;
    priority_queue<int, vector<int>> max_q;

    int cnt = 0;
    for (int i = 0; i < operations.size(); i++)
    {
        string cmd = operations[i];

        if (cnt == 0)
        {
            while (!min_q.empty())
                min_q.pop();
            while (!max_q.empty())
                max_q.pop();
        }

        if (cmd[0] == 'I')
        {
            min_q.push(stoi(cmd.substr(2)));
            max_q.push(stoi(cmd.substr(2)));
            cnt++;
        }
        else
        {
            if (cnt == 0)
                continue;
            if (cmd.substr(2) == "-1")
                min_q.pop();
            else
                max_q.pop();

            cnt--;
        }
    }

    if (cnt != 0)
    {
        answer[0] = max_q.top();
        answer[1] = min_q.top();
    }

    return answer;
}

int main()
{
    vector<string> oper1 = {"I 16", "D 1"};
    vector<string> oper2 = {"I 7", "I 5", "I -5", "D -1"};
    vector<string> oper3 = {"D 1", "D -1"};
    vector<string> oper4 = {"I 7", "I 5", "I -1", "I 70", "I 52", "I -1", "D -1", "D -1", "D -1"};
    vector<string> oper5 = {"I -45", "I 653", "D 1", "I -642", "I 45", "I 97", "D 1", "D -1", "I 333"}; //333, -45
    vector<string> oper6 = {"I -45", "I 653", "D 1", "I -642"};
    vector<string> oper7 = {"I 16", "I -5643", "D -1", "D 1", "D 1", "I 123", "D -1"}; //0, 0

    vector<int> answer = solution(oper7);

    cout << "answer: [";
    cout << answer[0] << ", " << answer[1] << "]";
    cout << endl;
}