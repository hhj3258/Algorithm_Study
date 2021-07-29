#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    int N;

    cin >> N;
    vector<int> nums(N);
    vector<int> positive_count(4001);
    vector<int> negative_count(4001);
    int temp;
    float sum = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> temp;
        nums[i] = temp;
        sum += temp;

        if (temp >= 0)
            positive_count[temp]++;
        else
            negative_count[abs(temp)]++;
    }

    sort(nums.begin(), nums.end());

    int a = round(sum / N);    //»ê¼úÆò±Õ
    int b = nums[(N - 1) / 2]; //Áß¾Ó°ª
    int c;

    int positive_max = *max_element(positive_count.begin(), positive_count.end());
    int negative_max = *max_element(negative_count.begin(), negative_count.end());

    int real_max;
    if (positive_max > negative_max)
        real_max = positive_max;
    else
        real_max = negative_max;

    int cnt = 0;
    for (int i = negative_count.size() - 1; i >= 0; i--)
    {

        if (negative_count[i] == real_max)
            cnt++;

        if (cnt == 2)
        {
            c = (-1 * i);
            break;
        }
    }

    int d = nums[nums.size() - 1] - nums[0]; //¹üÀ§

    cout << "answer" << endl;
    cout << a << endl;
    cout << b << endl;
    cout << c << endl;
    cout << d << endl;
}