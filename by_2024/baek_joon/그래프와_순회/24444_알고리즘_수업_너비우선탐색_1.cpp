#include <bits/stdc++.h>
using namespace std;

void Bfs(const vector<vector<int>> &graph, int startVertex)
{
    int visitedCnt = 0;
    vector<int> visitedVertexVec(graph.size());

    queue<int> bfsQ;
    bfsQ.push(startVertex);
    visitedVertexVec[startVertex] = ++visitedCnt;

    while (!bfsQ.empty())
    {
        int curVertex = bfsQ.front();
        bfsQ.pop();

        for (const auto &nextVertex : graph[curVertex])
        {
            bool isVisited = visitedVertexVec[nextVertex] != 0;
            if (isVisited)
                continue;

            bfsQ.push(nextVertex);
            visitedVertexVec[nextVertex] = ++visitedCnt;
        }
    }

    for (int i = 1; i < visitedVertexVec.size(); i++)
    {
        cout << visitedVertexVec[i] << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, R;
    cin >> N >> M >> R;

    vector<vector<int>> graph(N + 1);
    int u, v;
    for (int i = 0; i < M; i++)
    {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (auto &item : graph)
    {
        sort(item.begin(), item.end());
    }

    Bfs(graph, R);
}