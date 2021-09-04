#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int N;

int GCD(int a, int b)
{
    while (b != 0)
    {
        int r = a % b;
        a = b;
        b = r;
    }

    return a;
}

void Solve(vector<int> &nums)
{
    sort(nums.begin(), nums.end());

    int gcd = nums[1] - nums[0];
    for (int i = 2; i < N; i++)
    {
        gcd = GCD(gcd, nums[i] - nums[i - 1]);
    }

    vector<int> answer;
    for (int i = 2; i <= sqrt(gcd); i++)
    {
        if (gcd % i == 0)
        {
            answer.push_back(i);
            if (i * i != gcd)
                answer.push_back(gcd / i);
        }
    }
    answer.push_back(gcd);
    sort(answer.begin(), answer.end());

    for (int i : answer)
        cout << i << ' ';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    vector<int> nums(N);
    for (int i = 0; i < N; i++)
        cin >> nums[i];

    Solve(nums);
}