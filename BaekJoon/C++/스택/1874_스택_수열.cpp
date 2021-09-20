#include <bits/stdc++.h>
using namespace std;

int n;

void Solve(vector<int> &nums)
{
    int nums_idx = 0;

    stack<int> myStack;
    vector<char> ans;

    for (int i = 1; i <= n; i++)
    {
        myStack.push(i);
        ans.push_back('+');

        while (!myStack.empty() && myStack.top() == nums[nums_idx])
        {
            ans.push_back('-');
            myStack.pop();
            nums_idx++;
        }
    }

    if (!myStack.empty())
        cout << "NO";
    else
        for (char c : ans)
            cout << c << '\n';
}

int main()
{
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    Solve(nums);
}