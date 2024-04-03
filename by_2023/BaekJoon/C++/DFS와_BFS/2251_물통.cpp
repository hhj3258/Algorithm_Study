#include <bits/stdc++.h>
using namespace std;

set<int> answer;
int maxA, maxB, maxC;

auto CalcBottle(int start, int end, int maxEnd)
{
    if (start <= (maxEnd - end))
    {
        end = end + start;
        start = 0;
    }
    else if (start > (maxEnd - end))
    {
        start = start + end - maxEnd;
        end = maxEnd;
    }

    return make_pair(start, end);
}

struct Bottles
{
    int A, B, C;
};

bool visited[201][201][201];

void Solve(int A, int B, int C)
{
    queue<Bottles> q;
    q.push({A, B, C});

    while (!q.empty())
    {
        int nowA = q.front().A;
        int nowB = q.front().B;
        int nowC = q.front().C;
        q.pop();

        if (visited[nowA][nowB][nowC])
            continue;
        else
            visited[nowA][nowB][nowC] = true;

        if (nowA == 0)
        {
            answer.insert(nowC);
        }

        // A -> B
        auto ret = CalcBottle(nowA, nowB, maxB);
        q.push({ret.first, ret.second, nowC});
        // A -> C
        ret = CalcBottle(nowA, nowC, maxC);
        q.push({ret.first, nowB, ret.second});

        // B -> A
        ret = CalcBottle(nowB, nowA, maxA);
        q.push({ret.second, ret.first, nowC});
        // B -> C
        ret = CalcBottle(nowB, nowC, maxC);
        q.push({nowA, ret.first, ret.second});

        // C -> A
        ret = CalcBottle(nowC, nowA, maxA);
        q.push({ret.second, nowB, ret.first});
        // C -> B
        ret = CalcBottle(nowC, nowB, maxB);
        q.push({nowA, ret.second, ret.first});
    }

    for (auto &item : answer)
        cout << item << ' ';
}

int main()
{
    cin >> maxA >> maxB >> maxC;

    int A = 0, B = 0, C;
    C = maxC;

    Solve(A, B, C);
}