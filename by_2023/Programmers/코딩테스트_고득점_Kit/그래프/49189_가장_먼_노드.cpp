#include <bits/stdc++.h>

using namespace std;

void PrintGraph(vector<vector<int>> &graph, int n)
{
    for (int i = 1; i <= n; i++)
    {
        cout << i << " : ";
        for (int j = 0; j < graph[i].size(); j++)
        {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int dist[20001];

void FindMaxDist(const vector<vector<int>> &graph, int node)
{
    queue<int> q;
    q.push(node);
    dist[node] = 0;

    while (!q.empty())
    {
        node = q.front();
        q.pop();

        for (int i = 0; i < graph[node].size(); i++)
        {
            int nextNode = graph[node][i];

            if (dist[nextNode] != -1)
                continue;

            dist[nextNode] = dist[node] + 1; // 방문처리 겸 거리 기록
            q.push(nextNode);
        }
    }
}

int solution(int n, vector<vector<int>> edge)
{
    int answer = 0;

    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < edge.size(); i++)
    {
        int v1 = edge[i][0];
        int v2 = edge[i][1];

        graph[v1].push_back(v2);
        graph[v2].push_back(v1);

        dist[v1] = -1;
        dist[v2] = -1;
    }

    FindMaxDist(graph, 1);
    int maxDist = *max_element(dist, dist + n + 1);

    for (int i = 1; i <= n; i++)
    {
        if (dist[i] == maxDist)
            answer++;
    }

    return answer;
}