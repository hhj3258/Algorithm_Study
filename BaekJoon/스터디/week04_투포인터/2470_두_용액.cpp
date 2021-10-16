#include <bits/stdc++.h>
using namespace std;

int N;

struct T
{
    long long sum = 0;
    int left = 0;
    int right = 0;
};

bool cmp(T a, T b)
{
    return abs(a.sum) < abs(b.sum);
}

void Solve(vector<int> &nums)
{
    sort(nums.begin(), nums.end());

    int left = 0;
    int right = N - 1;
    vector<T> answer;
    while (left < right)
    {
        long long sum = nums[left] + nums[right];
        T t;
        t.left = left;
        t.right = right;
        t.sum = sum;
        answer.push_back(t);

        if (sum == 0)
        {
            cout << nums[left] << ' ' << nums[right] << '\n';
            return;
        }
        else if (sum > 0)
        {
            right--;
        }
        else if (sum < 0)
        {
            left++;
        }
    }

    sort(answer.begin(), answer.end(), cmp);

    cout << nums[answer[0].left] << ' ' << nums[answer[0].right];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    vector<int> nums(N);
    for (int i = 0; i < N; i++)
        cin >> nums[i];
    Solve(nums);
}