#include <bits/stdc++.h>
using namespace std;

vector<string> solution(vector<vector<int>> line)
{
    vector<pair<long long, long long>> xy;
    long long max_x = LLONG_MIN, max_y = LLONG_MIN;
    long long min_y = LLONG_MAX, min_x = LLONG_MAX;

    for (int i = 0; i < line.size(); i++)
    {
        vector<int> i_line = line[i];

        for (int j = i + 1; j < line.size(); j++)
        {
            vector<int> j_line = line[j];

            if (i_line[0] == j_line[0] && i_line[1] == j_line[1])
                continue; // 기울기 같음

            long long A = i_line[0], B = i_line[1];
            long long C = j_line[0], D = j_line[1];
            long long E = i_line[2], F = j_line[2];

            long long down = A * D - B * C;
            long long x_up = B * F - E * D;
            long long y_up = E * C - A * F;

            if (down == 0)
                continue;

            if (x_up % down != 0 || y_up % down != 0)
                continue; // 정수 판별

            long long x = x_up / down;
            long long y = y_up / down;

            xy.push_back({x, y});

            max_x = max(max_x, x);
            min_x = min(min_x, x);
            max_y = max(max_y, y);
            min_y = min(min_y, y);
        }
    }

    string tmp = string(max_x - min_x + 1, '.');
    vector<string> answer(max_y - min_y + 1, tmp);

    for (int i = 0; i < xy.size(); i++)
    {
        long long y = abs(xy[i].second - max_y);
        long long x = abs(xy[i].first - min_x);
        answer[y][x] = '*';
    }

    return answer;
}