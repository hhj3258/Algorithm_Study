#include <bits/stdc++.h>
using namespace std;
#define MAX 101

void ADJ(vector<vector<int>> &adj, vector<vector<int>> wires, int del_wire)
{
    int v1, v2;
    for (int i = 0; i < wires.size(); i++)
    {
        if (i == del_wire)
            continue;

        v1 = wires[i][0];
        v2 = wires[i][1];

        adj[v1].push_back(v2);
        adj[v2].push_back(v1);
    }
}

bool visited[MAX];
int cnt = 0;

void DFS(vector<vector<int>> adj, int v)
{
    cnt++;
    visited[v] = true;

    for (int i = 0; i < adj[v].size(); i++)
    {
        int next = adj[v][i];

        if (visited[next] == 0)
            DFS(adj, next);
    }
}

int solution(int n, vector<vector<int>> wires)
{
    int answer = MAX;

    for (int i = 0; i < wires.size(); i++)
    {
        vector<vector<int>> adj(n + 1);
        ADJ(adj, wires, i);

        int min_v = MAX;
        int max_v = -1;

        for (int j = 1; j < adj.size(); j++)
        {
            DFS(adj, j);

            memset(visited, false, sizeof(visited));

            min_v = min(min_v, cnt);
            max_v = max(max_v, cnt);

            cnt = 0;

            if (min_v != max_v)
                break;
        }

        answer = min(answer, max_v - min_v);
    }

    return answer;
}

int main()
{
    int n = 9;
    vector<vector<int>> wires = {{1, 3}, {2, 3}, {3, 4}, {4, 5}, {4, 6}, {4, 7}, {7, 8}, {7, 9}};
    cout << solution(n, wires);
}