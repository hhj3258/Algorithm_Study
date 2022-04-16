#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool visited[101];
int virus = 0;

void Solve(int start, const vector<vector<int>> &graph)
{
    queue<int> q;
    q.emplace(start);
    visited[start] = true;

    while (!q.empty())
    {
        int now_v = q.front();
        q.pop();

        for (auto &next_v : graph[now_v])
        {
            if (!visited[next_v])
            {
                q.emplace(next_v);
                visited[next_v] = true;
                virus++;
            }
        }
    }
}

int main()
{
    int N;
    cin >> N;

    int M;
    cin >> M;

    vector<vector<int>> graph(N + 1);
    int v1, v2;
    for (int i = 0; i < M; i++)
    {
        cin >> v1 >> v2;

        graph[v1].emplace_back(v2);
        graph[v2].emplace_back(v1);
    }

    Solve(1, graph);

    cout << virus;
}