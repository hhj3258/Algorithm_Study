#include <bits/stdc++.h>
using namespace std;

#define MAX 987654321

int human1, human2; // 서로 다른 사람 2명(알고자 하는 관계)
bool visited[101];

int answer = MAX;

void Solve(vector<vector<int>> &vec, int v1, int depth)
{
    if (v1 == human2)
    {
        answer = min(answer, depth);
        return;
    }

    for (auto &item : vec[v1])
    {
        if (visited[item])
            continue;

        visited[item] = true;
        Solve(vec, item, depth + 1);
        visited[item] = false;
    }
}

int main()
{
    int n; // 사람 수
    cin >> n;

    cin >> human1 >> human2;

    int m; // 부모 자식들 간의 관계의 개수
    cin >> m;

    int x, y; // x는 y의 부모
    vector<vector<int>> vec(n + 1);
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        vec[x].emplace_back(y);
        vec[y].emplace_back(x);
    }

    visited[human1] = true;
    Solve(vec, human1, 0);

    if (answer < MAX)
        cout << answer;
    else
        cout << -1;
}