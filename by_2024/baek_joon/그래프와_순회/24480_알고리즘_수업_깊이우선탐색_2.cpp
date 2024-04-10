#include <bits/stdc++.h>

using namespace std;

vector<int> _visitedVertexVec;
int _visitCnt = 0;

void Dfs(vector<vector<int>> &graph, int startVertex)
{
    _visitedVertexVec[startVertex] = ++_visitCnt;

    for (int i = 0; i < graph[startVertex].size(); i++)
    {
        int nextVertex = graph[startVertex][i];

        bool isAlreadyVisited = _visitedVertexVec[nextVertex] > 0;
        if (isAlreadyVisited)
            continue;

        Dfs(graph, nextVertex);
    }
}

bool DecCompare(int a, int b)
{
    return a > b;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, R;
    cin >> N >> M >> R;

    _visitedVertexVec.resize(N + 1);

    int u, v;
    vector<vector<int>> graph(N + 1);
    for (int i = 0; i < M; i++)
    {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (int i = 0; i < graph.size(); i++)
    {
        sort(graph[i].begin(), graph[i].end(), DecCompare);
    }

    Dfs(graph, R);

    for (int i = 1; i < _visitedVertexVec.size(); i++)
    {
        cout << _visitedVertexVec[i] << '\n';
    }
}