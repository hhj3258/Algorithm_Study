#include <iostream>
using namespace std;

int main()
{
    int max_num = 0;
    cin >> max_num;

    int cnt = 99;

    if (max_num < 100)
    {
        cout << max_num;
    }
    else
    {
        for (int i = 100; i <= max_num; i++)
        {
            int three = i / 100;
            int two = (i % 100) / 10;
            int one = (i % 100) % 10;

            int three_two = three - two;
            int two_one = two - one;

            if (three_two == two_one)
                cnt++;
        }
        cout << cnt;
    }
}