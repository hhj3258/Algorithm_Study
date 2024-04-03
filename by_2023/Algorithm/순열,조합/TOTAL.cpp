#include <iostream>
#include <vector>

using namespace std;

int n, m;

//순열
void DFS_1(int cnt, vector<int> nums, vector<bool> visited)
{
    if (cnt == m)
    {
        for (int i = 0; i < m; i++)
            cout << nums[i] << ' ';
        cout << '\n';
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (visited[i])
            continue;

        visited[i] = true;
        nums[cnt] = i + 1;
        DFS_1(cnt + 1, nums, visited);
        visited[i] = false;
    }
}

//조합
void DFS_2(int cnt, int num, vector<int> nums)
{
    if (cnt == m)
    {
        for (int i = 0; i < m; i++)
            cout << nums[i] << ' ';
        cout << '\n';
        return;
    }

    for (int i = num; i < n; i++)
    {
        nums[cnt] = i + 1;
        DFS_2(cnt + 1, i + 1, nums);
    }
}

//중복순열
void DFS_3(int cnt, vector<int> nums)
{
    if (cnt == m)
    {
        for (int i = 0; i < m; i++)
            cout << nums[i] << ' ';
        cout << '\n';
        return;
    }

    for (int i = 0; i < n; i++)
    {
        nums[cnt] = i + 1;
        DFS_3(cnt + 1, nums);
    }
}

//중복조합
void DFS_4(int cnt, int num, vector<int> nums)
{
    if (cnt == m)
    {
        for (int i = 0; i < m; i++)
            cout << nums[i] << ' ';
        cout << '\n';
        return;
    }

    for (int i = num; i < n; i++)
    {
        nums[cnt] = i + 1;
        DFS_4(cnt + 1, i, nums);
    }
}

int main()
{
    cin >> n >> m;
    vector<int> nums(n);

    DFS_4(0, 0, nums);
}