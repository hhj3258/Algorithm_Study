#include <bits/stdc++.h>
using namespace std;

double answer = INT_MAX;

double GetVectorMagnitude(vector<pair<int, int>> &pos, vector<int> temp, int r)
{
    double x = 0, y = 0;
    vector<bool> visited(pos.size());

    for (int i = 0; i < r; i++)
    {
        int idx = temp[i];
        visited[idx] = true;

        x += pos[idx].first;
        y += pos[idx].second;
    }

    for (int i = 0; i < pos.size(); i++)
    {
        if (visited[i])
            continue;

        x -= pos[i].first;
        y -= pos[i].second;
    }

    return sqrt(x * x + y * y);
}

void Combination(vector<pair<int, int>> &pos, vector<int> temp, int index, int r, int depth)
{
    if (depth == r)
    {
        double magnitude = GetVectorMagnitude(pos, temp, r);
        answer = min(answer, magnitude);

        return;
    }

    for (int i = index; i < pos.size(); i++)
    {
        temp[depth] = i;
        Combination(pos, temp, i + 1, r, depth + 1);
    }
}

int main()
{
    int T;
    cin >> T;

    cout << fixed;
    cout.precision(7);

    for (int t = 0; t < T; t++)
    {
        int N;
        cin >> N;

        vector<pair<int, int>> pos(N);
        for (int i = 0; i < N; i++)
        {
            // first = x , second = y
            cin >> pos[i].first >> pos[i].second;
        }

        answer = INT_MAX;
        Combination(pos, vector<int>(N / 2), 0, N / 2, 0);
        cout << answer << '\n';
    }
}