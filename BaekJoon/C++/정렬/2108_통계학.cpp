#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;

int MostNum(map<int, int> most_map)
{
    int max = -1;
    int c = 0;
    for (auto iter = most_map.begin(); iter != most_map.end(); iter++)
    {
        if ((*iter).second > max)
        {
            max = (*iter).second;
            c = (*iter).first;
        }
    }

    int cnt = 0;
    for (auto iter = most_map.begin(); iter != most_map.end(); iter++)
    {
        if ((*iter).second == max)
            cnt++;

        if (cnt == 2)
        {
            c = (*iter).first;
            break;
        }
    }

    return c;
}

int main()
{
    int N;
    cin >> N;

    vector<int> nums(N);
    map<int, int> most_map;

    int temp = 0;
    double sum = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> temp;
        nums[i] = temp;
        sum += temp;
        most_map[temp]++;
    }

    sort(nums.begin(), nums.end());

    int a = round(sum / N);
    int b = nums[N / 2];
    int c = MostNum(most_map);
    int d = nums[nums.size() - 1] - nums[0];

    cout << a << endl;
    cout << b << endl;
    cout << c << endl;
    cout << d << endl;
}