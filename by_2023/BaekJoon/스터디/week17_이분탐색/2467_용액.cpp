#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<int> nums(N);
    for (int i = 0; i < N; i++)
        cin >> nums[i];

    int temp = INT_MAX;
    int ans_left = 0;
    int ans_right = N - 1;

    int left = 0;
    int right = N - 1;
    while (left < right)
    {
        int sum = nums[left] + nums[right];

        if (abs(temp) > abs(sum))
        {
            ans_left = left;
            ans_right = right;
            temp = sum;
        }

        if (sum == 0)
        {
            break;
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

    cout << nums[ans_left] << ' ' << nums[ans_right];
}