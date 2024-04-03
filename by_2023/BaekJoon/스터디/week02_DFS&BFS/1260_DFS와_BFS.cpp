#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

bool visited[1001];

void DFS(int now_v, const vector<vector<int>> &graph)
{
    cout << now_v << ' ';

    visited[now_v] = true;

    for (auto &next_v : graph[now_v])
    {
        if (!visited[next_v])
        {
            DFS(next_v, graph);
        }
    }
}

void BFS(int start, const vector<vector<int>> &graph)
{
    queue<int> q;
    q.emplace(start);
    visited[start] = true;

    while (!q.empty())
    {
        int now_v = q.front();
        q.pop();

        cout << now_v << ' ';

        for (auto &next_v : graph[now_v])
        {
            if (!visited[next_v])
            {
                q.emplace(next_v);
                visited[next_v] = true;
            }
        }
    }
}

int main()
{
    int N, M, V;
    cin >> N >> M >> V;

    vector<vector<int>> graph(N + 1);
    int v1, v2;
    for (int i = 0; i < M; ++i)
    {
        cin >> v1 >> v2;

        graph[v1].emplace_back(v2);
        graph[v2].emplace_back(v1);
    }

    // 방문할 수 있는 정점이 여러 개인 경우 정점 번호가 작은 것부터
    for (auto &v : graph)
        sort(v.begin(), v.end());

    DFS(V, graph);
    cout << '\n';

    fill(visited, visited + 1001, false);

    BFS(V, graph);
}