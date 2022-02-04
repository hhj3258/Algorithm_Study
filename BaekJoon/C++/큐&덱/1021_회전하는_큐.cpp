#include <iostream>
#include <queue>

using namespace std;

int FindTarget(queue<int> &q, const int targetIdx)
{
    // 최소한의 Shift 횟수를 넣어줄 것
    int cnt = 0;

    // LeftShift만 수행해서 일단 cnt에는
    // 왼쪽으로 돌렸을 때의 횟수를 넣어준다.
    while (q.front() != targetIdx)
    {
        q.push(q.front());
        q.pop();

        cnt++;
    }

    // 만약 LeftShift 횟수가 RightShift 횟수보다 크다면
    // cnt = RightShift 횟수
    if (cnt > q.size() - cnt)
        cnt = q.size() - cnt;

    return cnt;
}

void Solve(queue<int> &targetIdxs, queue<int> &q)
{
    int answer = 0;
    while (!targetIdxs.empty())
    {
        if (targetIdxs.front() == q.front())
        {
            targetIdxs.pop();
            q.pop();
        }
        else
        {
            answer += FindTarget(q, targetIdxs.front());
        }
    }

    cout << answer;
}

int main()
{
    int N, M;
    cin >> N >> M;

    queue<int> targetIdxs;
    int input;
    for (int i = 0; i < M; i++)
    {
        cin >> input;
        targetIdxs.push(input);
    }

    queue<int> q;
    for (int i = 1; i <= N; i++)
        q.push(i);

    Solve(targetIdxs, q);
}