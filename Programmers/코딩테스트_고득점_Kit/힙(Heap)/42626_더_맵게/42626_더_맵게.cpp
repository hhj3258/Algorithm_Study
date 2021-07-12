#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K)
{
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>>
        pq2(scoville.begin(), scoville.end());

    if (pq2.top() >= K)
        return answer;

    int scoville1, scoville2, new_scoville;
    while (pq2.size() > 1)
    {
        scoville1 = pq2.top();
        pq2.pop();

        scoville2 = pq2.top();
        pq2.pop();

        new_scoville = scoville1 + (scoville2 * 2);
        pq2.push(new_scoville);

        answer++;

        if (pq2.top() >= K)
            break;
    }

    if (pq2.top() < K)
        answer = -1;

    return answer;
}

int main()
{
    vector<int> scoville = {1, 2, 3, 9, 10, 12};
    int K = 50;

    vector<int> scoville2 = {10, 10};
    int K2 = 0;

    vector<int> scoville3 = {10, 0};
    int K3 = 11;

    vector<int> scoville4 = {1, 2, 3, 9, 10, 12};
    int K4 = 7;

    vector<int> scoville5 = {0, 0, 3, 9, 10, 12};
    int K5 = 7;

    int answer = solution(scoville5, K5);
    cout << "answer: " << answer << endl;
}
