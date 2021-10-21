#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> enter, vector<int> leave)
{
    int num = enter.size();

    vector<int> answer(num);
    vector<int> room;
    vector<vector<int>> visit(num + 1, vector<int>(num + 1));
    vector<vector<int>> meet(num + 1, vector<int>(1));

    int ei = 0, li = 0;
    while (ei < num || li < num)
    {
        bool chk = false;
        for (int i = 0; i < room.size(); i++)
        {
            if (leave[li] == room[i])
            {
                chk = true;
                room.erase(room.begin() + i);
                li += 1;

                break;
            }
        }

        if (!chk)
        {
            for (int i = 0; i < room.size(); i++)
                meet[enter[ei]].push_back(room[i]);

            room.push_back(enter[ei]);
            ei += 1;
        }
    }

    for (int i = 1; i < meet.size(); i++)
    {
        cout << i << ": ";
        for (int j = 1; j < meet[i].size(); j++)
        {
            cout << meet[i][j] << ' ';
            visit[i][meet[i][j]] = 1;
            visit[meet[i][j]][i] = 1;
        }
        cout << endl;
    }

    for (int i = 1; i < visit.size(); i++)
        for (int j = 1; j < visit.size(); j++)
            answer[i - 1] += visit[i][j];

    return answer;
}

int main()
{
    vector<int> enter1 = {1, 3, 2};
    vector<int> leave1 = {1, 2, 3};

    vector<int> enter2 = {1, 4, 2, 3};
    vector<int> leave2 = {2, 1, 3, 4};

    vector<int> enter3 = {3, 2, 1};
    vector<int> leave3 = {2, 1, 3};

    vector<int> enter4 = {1, 4, 2, 3};
    vector<int> leave4 = {2, 1, 4, 3};

    vector<int> answer = solution(enter2, leave2);

    cout << "answer: ";
    for (int i : answer)
        cout << i << ' ';
}