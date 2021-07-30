#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N; //1<=N<=1,000,000
    cin >> N;

    vector<int> nums;

    int temp;
    for (int i = 0; i < N; i++)
    {
        cin >> temp;
        nums.push_back(temp);
    }

    vector<int> sorted_nums = nums;
    sort(sorted_nums.begin(), sorted_nums.end());

    sorted_nums[0] = 0;
}