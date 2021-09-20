#include <bits/stdc++.h>
using namespace std;

void Solve(vector<int> &nums)
{
    int asc_num = 1;
    int idx = 0;

    stack<int> myStack;
    vector<int> answer;

    for (int i : nums)
        cout << i << ' ';
    cout << endl;

    while (idx < nums.size())
    {
        if (!myStack.empty())
        {
            while (myStack.top() == nums[idx])
            {
                cout << "stack: " << myStack.top() << " nums[" << idx << "]: " << nums[idx] << endl;
                answer.push_back(myStack.top());
                myStack.pop();
                idx++;

                if (myStack.empty() || idx == nums.size())
                    break;
            }
        }

        myStack.push(asc_num++);
    }

    for (int i : answer)
        cout << i << ' ';
    cout << endl;
}

int main()
{
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < nums.size(); i++)
        cin >> nums[i];

    Solve(nums);
}