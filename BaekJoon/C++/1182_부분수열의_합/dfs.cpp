#include <iostream>
#include <vector>

using namespace std;

int N, S;
int answer = 0;

void dfs(vector<int> nums, int idx, int sum)
{
    if (idx >= N)
    {
        return;
    }

    if (sum + nums[idx] == S)
    {
        answer++;
    }

    dfs(nums, idx + 1, sum);
    dfs(nums, idx + 1, sum + nums[idx]);
}

int main()
{
    cin >> N >> S;
    vector<int> nums(N);

    for (int i = 0; i < N; i++)
        cin >> nums[i];

    dfs(nums, 0, 0);
    cout << answer;
}