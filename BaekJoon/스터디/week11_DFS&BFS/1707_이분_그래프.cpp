#include <bits/stdc++.h>
using namespace std;

#define RED 1
#define BLUE 2

int V, E;

void Solve(vector<vector<int>> &graph, vector<int> &visited, int start_node)
{
    queue<int> q;
    int color = RED;

    visited[start_node] = color;
    q.push(start_node);

    while (!q.empty())
    {
        int now = q.front();
        q.pop();

        if (visited[now] == RED)
            color = BLUE;
        else if (visited[now] == BLUE)
            color = RED;

        for (int i = 0; i < graph[now].size(); i++)
        {
            int next_node = graph[now][i];

            if (!visited[next_node])
            {
                visited[next_node] = color;
                q.push(next_node);
            }
        }
    }
}

bool IsBipart(vector<vector<int>> &graph, vector<int> &visited)
{
    for (int i = 1; i <= V; i++)
    {
        for (int j = 0; j < graph[i].size(); j++)
        {
            int next_node = graph[i][j];

            if (visited[i] == visited[next_node])
            {
                return false;
            }
        }
    }

    return true;
}

int main()
{
    int K;
    // 테스트케이스
    cin >> K;

    for (int i = 0; i < K; i++)
    {
        // 정점 개수 >> 간선 개수
        cin >> V >> E;

        vector<vector<int>> graph(V + 1);
        vector<int> visited(V + 1);
        int n1, n2;
        for (int j = 0; j < E; j++)
        {
            cin >> n1 >> n2;
            graph[n1].push_back(n2);
            graph[n2].push_back(n1);
        }

        for (int j = 1; j <= V; j++)
        {
            if (!visited[j])
            {
                Solve(graph, visited, j);
            }
        }

        if (IsBipart(graph, visited))
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
}