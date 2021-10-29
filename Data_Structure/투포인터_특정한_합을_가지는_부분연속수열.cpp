#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n = 5;
    int m = 5;
    int data[] = {1, 2, 3, 2, 5};

    int result = 0;
    int sum = 0;
    int end = 0;

    for (int i = 0; i < n; i++)
    {
        while (sum < m && end < n)
        {
            sum += data[end++];
        }

        if (sum == m)
            result++;

        sum -= data[i]; //start(i)를 우측으로 이동하기 위해서
    }

    cout << result;
}