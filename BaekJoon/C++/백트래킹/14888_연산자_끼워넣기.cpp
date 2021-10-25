#include <iostream>
#include <vector>
using namespace std;

int N;
int operland[11];
int operators[4];
int maxV = -1000000001;
int minV = 1000000001;

void OperSteal(int idx, int result)
{
    if (idx == N)
    {
        if (result > maxV)
            maxV = result;
        if (result < minV)
            minV = result;
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        if (operators[i] > 0)
        {
            operators[i]--;

            if (i == 0)
                OperSteal(idx + 1, result + operland[idx]);
            if (i == 1)
                OperSteal(idx + 1, result - operland[idx]);
            if (i == 2)
                OperSteal(idx + 1, result * operland[idx]);
            if (i == 3)
                OperSteal(idx + 1, result / operland[idx]);

            operators[i]++;
        }
    }
}

int main()
{

    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> operland[i];

    for (int i = 0; i < 4; i++)
        cin >> operators[i];

    OperSteal(1, operland[0]);

    cout << maxV << '\n'
         << minV;
}