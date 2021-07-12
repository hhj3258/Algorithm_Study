#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Work
{
    int start_t, run_t;
};

struct cmp
{
    bool operator()(Work &a, Work &b)
    {
        if (a.run_t == b.run_t)
            return a.start_t > b.start_t;
        else
            return a.run_t > b.run_t;
    }
};

int solution(vector<vector<int>> jobs)
{
    int answer = 0;
    sort(jobs.begin(), jobs.end());
    priority_queue<Work, vector<Work>, cmp> low_run_q;

    int time = 0;
    int index = 0;
    do
    {
        //요청 시간이 현재 시간보다 작으면
        if (index < jobs.size() && jobs[index][0] <= time)
        {
            //우선순위 큐에 push
            low_run_q.push({jobs[index][0], jobs[index][1]});
            index++;

            //index에 해당하는 요청시간이 time과 같아질 때까지 반복
            continue;
        }

        //현재 큐에 처리중인 작업이 있다면
        if (!low_run_q.empty())
        {
            //현재시간 += 현재 작업의 소요시간
            time += low_run_q.top().run_t;
            //작업의 요청~종료까지 걸린 시간 += 현재시간 - 현재 작업의 요청시간
            answer += time - low_run_q.top().start_t;
            low_run_q.pop();
        }
        else
        {
            //현재 큐가 비었다면(처리중인 작업이 없다면)
            //현재시간 = 다음 처리할 작업의 요청시간
            time = jobs[index][0];
        }

    } while (index != jobs.size() || !low_run_q.empty());

    answer /= jobs.size();
    return answer;
}

int main()
{
    vector<vector<int>> jobs1 = {{0, 3}, {1, 9}, {2, 6}};
    vector<vector<int>> jobs2 = {{15, 2}, {2, 2}, {0, 3}, {1, 9}, {2, 6}, {4, 20}, {5, 1}};
    vector<vector<int>> jobs3 = {{0, 10}, {4, 10}, {15, 2}, {5, 11}};
    vector<vector<int>> jobs4 = {{300, 1}};

    int answer = solution(jobs4);
    cout << "answer: " << answer << endl;
}