#include <bits/stdc++.h>
using namespace std;

int n;
vector<bool> visited(9);

//순열
void DFS(vector<int> nums, int cnt, vector<vector<int>> &orders)
{
    if (cnt == n)
    {
        orders.push_back(nums);
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (visited[i])
            continue;

        visited[i] = true;
        nums[cnt] = i;
        DFS(nums, cnt + 1, orders);
        visited[i] = false;
    }
}

int solution(int k, vector<vector<int>> dungeons)
{
    int answer = 0;

    n = dungeons.size();
    vector<int> nums(n);
    vector<vector<int>> orders;
    DFS(nums, 0, orders);

    for (int i = 0; i < orders.size(); i++)
    {
        int temp_k = k;
        int cnt = 0;

        for (int j = 0; j < orders[i].size(); j++)
        {
            if (temp_k >= dungeons[orders[i][j]][0])
            {
                temp_k = temp_k - dungeons[orders[i][j]][1]; // 소모 피로도
                cnt++;
            }
        }

        answer = max(answer, cnt);
    }

    return answer;
}

int main()
{
    int k = 80;
    vector<vector<int>> dungeons = {{80, 20}, {50, 40}, {30, 10}};

    solution(k, dungeons);
}