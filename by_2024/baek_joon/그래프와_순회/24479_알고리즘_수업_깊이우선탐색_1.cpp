#include <bits/stdc++.h>

using namespace std;

int visitedVertexArr[100001];
int visitCnt = 1;

void Dfs(const vector<vector<int>> &graph, int startVertex)
{
    visitedVertexArr[startVertex] = visitCnt++;

    for (int i = 0; i < graph[startVertex].size(); i++)
    {
        int nextVertex = graph[startVertex][i];
        if (visitedVertexArr[nextVertex] == 0)
        {
            Dfs(graph, nextVertex);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, r;
    cin >> n >> m >> r;

    vector<vector<int>> graph(n + 1);
    int u, v;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (auto &item : graph)
    {
        sort(item.begin(), item.end());
    }

    Dfs(graph, r);

    for (int i = 1; i < graph.size(); i++)
    {
        cout << visitedVertexArr[i] << '\n';
    }
}