#include <iostream>
#include <vector>
using namespace std;

int N, S;
int answer = 0;

void Solve(vector<int> nums)
{

    for (int i = 1; i < (1 << nums.size()); i++)
    {
        int sum = 0;
        //vector<int> temp;
        for (int j = 0; j < nums.size(); j++)
        {
            //j = 1, 2, 4, 8 ...
            if ((i & (1 << j)) != 0)
            {
                //temp.push_back(nums[j]);
                sum += nums[j];
            }
        }

        if (sum == S)
        {
            // for (int i : temp)
            //     cout << i << ' ';
            // cout << endl;
            answer++;
        }
    }
}

int main()
{
    cin >> N >> S;
    vector<int> nums(N);
    for (int i = 0; i < N; i++)
        cin >> nums[i];

    Solve(nums);
    cout << answer;
}