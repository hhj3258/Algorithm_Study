#include <iostream>
using namespace std;

long long solution(int price, int money, int count)
{
    long long answer = money;

    for (int i = 1; i <= count; i++)
        answer -= price * i;

    return answer = answer >= 0 ? 0 : abs(answer);
}

int main()
{
    int price, money, count;
    cin >> price >> money >> count;

    long long answer = solution(price, money, count);

    cout << answer;
}