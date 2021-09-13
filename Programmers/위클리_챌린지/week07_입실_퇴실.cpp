#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> enter, vector<int> leave)
{
    vector<int> answer(enter.size() + 1);
    vector<int> room;

    map<int, set<int>> map;

    while (leave.size() > 0)
    {
        for (auto map_it = map.begin(); map_it != map.end(); map_it++)
        {
            for (int i = 0; i < room.size(); i++)
                if ((*map_it).first != room[i])
                    (*map_it).second.insert(room[i]);
        }
        if (enter.size() > 0)
        {
            map[enter.front()];
            room.push_back(enter.front());
            enter.erase(enter.begin());
        }

        cout << "room: ";
        for (int i = 0; i < room.size(); i++)
            cout << room[i] << ' ';
        cout << endl;

        cout << "enter: ";
        for (int i = 0; i < enter.size(); i++)
            cout << enter[i] << ' ';
        cout << endl;

        cout << "leave: ";
        for (int i = 0; i < leave.size(); i++)
            cout << leave[i] << ' ';
        cout << endl;

        auto it = find(room.begin(), room.end(), leave.front());
        if (it != room.end())
        {
            room.erase(it);
            leave.erase(leave.begin());
        }

        // cout << "answer: ";
        // for (int i = 0; i < answer.size(); i++)
        //     cout << answer[i] << ' ';
        // cout << endl;

        cout << endl;
    }

    for (auto map_it = map.begin(); map_it != map.end(); map_it++)
    {
        cout << (*map_it).first << ": ";
        for (auto set_it = (*map_it).second.begin(); set_it != (*map_it).second.end(); set_it++)
        {
            cout << (*set_it);
        }
        cout << endl;
    }

    cout << "answer: ";
    for (int i : answer)
        cout << i << ' ';

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

    solution(enter2, leave2);
}