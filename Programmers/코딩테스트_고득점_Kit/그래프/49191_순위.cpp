#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> results)
{
    int answer = 0;

    vector<vector<bool>> graph(n + 1, vector<bool>(n + 1));
    for (int i = 0; i < results.size(); i++)
    {
        int v1 = results[i][0];
        int v2 = results[i][1];

        graph[v1][v2] = true;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int k = 1; k <= n; k++)
            {
                if (graph[j][i] && graph[i][k])
                {
                    graph[j][k] = true;
                }
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        int cnt = 0;
        for (int j = 1; j <= n; j++)
        {
            // i가 j에게 이겼거나, i가 j에게 졌다면
            if (graph[i][j] || graph[j][i])
                // 경기수 + 1
                cnt++;
        }

        // 경기수가 인원수 - 1 이라면 순위를 정할 수 있다.
        if (cnt == n - 1)
            answer++;
    }

    return answer;
}