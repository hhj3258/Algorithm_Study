#include <bits/stdc++.h>
using namespace std;
#define MAX 101

void ADJ(vector<vector<int>> &adj, vector<vector<int>> wires, int del_v)
{
    int v1, v2;
    for (int i = 0; i < wires.size(); i++)
    {
        if (i == del_v)
            continue;

        v1 = wires[i][0];
        v2 = wires[i][1];

        adj[v1].push_back(v2);
        adj[v2].push_back(v1);
    }
}

bool visited[MAX];
int cnt = 0;

void dfs(vector<vector<int>> adj, int v)
{
    cnt++;
    visited[v] = true;

    for (int i = 0; i < adj[v].size(); i++)
    {
        int next = adj[v][i];

        if (visited[next] == 0)
            dfs(adj, next);
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
            dfs(adj, j);

            for (int k = 0; k < MAX; k++)
                visited[k] = false;

            min_v = min(min_v, cnt);
            max_v = max(max_v, cnt);

            cnt = 0;
        }

        answer = min(answer, max_v - min_v);
    }

    return answer;
}

int main()
{
    int n = 9;
    vector<vector<int>> wires = {{1, 3}, {2, 3}, {3, 4}, {4, 5}, {4, 6}, {4, 7}, {7, 8}, {7, 9}};
    solution(n, wires);
}