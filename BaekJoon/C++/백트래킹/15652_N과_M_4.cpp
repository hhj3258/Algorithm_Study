#include <iostream>
#include <vector>

using namespace std;

int n, m;

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