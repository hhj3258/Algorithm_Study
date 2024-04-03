#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}

vector<pair<int, int>> CoordinateZip(vector<pair<int, int>> nums)
{
    sort(nums.begin(), nums.end());

    int zip_num = -1;
    int origin_temp = 1000000001;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i].first == origin_temp)
        {
            origin_temp = nums[i].first;
            nums[i].first = zip_num;
        }
        else
        {
            origin_temp = nums[i].first;
            nums[i].first = ++zip_num;
        }
    }

    sort(nums.begin(), nums.end(), cmp);

    return nums;
}

int main()
{
    int N; //1<=N<=1,000,000
    cin >> N;

    vector<pair<int, int>> nums;

    int temp;
    for (int i = 0; i < N; i++)
    {
        cin >> temp;
        nums.push_back(make_pair(temp, i));
    }

    nums = CoordinateZip(nums);

    for (int i = 0; i < nums.size(); i++)
        cout << nums[i].first << ' ';
}