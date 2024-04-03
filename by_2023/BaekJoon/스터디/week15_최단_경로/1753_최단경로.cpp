#include <queue>
#include <vector>
#include <iostream>
#include <limits.h>
using namespace std;

const int Size = 20001;
int dist_arr[Size];

void Dijkstra(const vector<vector<pair<int, int>>> &graph, const int start)
{
    priority_queue<pair<int, int>> pq;
    // start 부터 start 까지의 거리 = 0
    pq.emplace(0, start);
    dist_arr[start] = 0;

    while (!pq.empty())
    {
        // pq가 내림차순이므로 오름차순 정렬하기 위해 마이너스를 붙여줌
        int dist = -pq.top().first;
        int now_v1 = pq.top().second;
        pq.pop();

        // 현재 테이블에 저장된 now_v1까지의 거리가 우선순위 큐에서 꺼낸 거리보다
        // 작다면 무시한다.(더 긴 거리를 테이블에 넣을 필요가 없으므로)
        if (dist_arr[now_v1] < dist)
            continue;

        // now_v1의 인접노드 탐색
        for (auto v2 : graph[now_v1])
        {
            int now_v2 = v2.first;
            // dist = v1까지 최단 거리
            // cost = dist + v1에서 v2까지 거리
            int cost = dist + v2.second;

            // 더 짧은 now_v2까지의 거리를 발견하면 갱신
            if (dist_arr[now_v2] > cost)
            {
                dist_arr[now_v2] = cost;
                pq.emplace(-cost, now_v2);
            }
        }
    }
}

int main()
{
    // 정점 수, 간선 수
    int V, E;
    cin >> V >> E;

    // 시작 정점
    int K;
    cin >> K;

    // 정점 번호는 1부터 시작
    vector<vector<pair<int, int>>> graph(V + 1);
    int v1, v2, cost;
    for (int i = 0; i < E; i++)
    {
        cin >> v1 >> v2 >> cost;

        // v1 에서 v2로 가는 가중치는 cost
        graph[v1].emplace_back(v2, cost);
    }

    fill(dist_arr, dist_arr + Size, INT_MAX);
    Dijkstra(graph, K);

    for (int i = 1; i <= V; i++)
    {
        if (dist_arr[i] == INT_MAX)
            cout << "INF" << '\n';
        else
            cout << dist_arr[i] << '\n';
    }
}