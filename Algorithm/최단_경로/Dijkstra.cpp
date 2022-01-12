#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define MAX 100000000

// 노드 사이의 거리를 저장할 배열
int dist_arr[100001];

void Dijkstra(vector<vector<pair<int, int>>> &graph, int start)
{
    priority_queue<pair<int, int>> pq;
    // {최단 경로, 시작 노드}
    // 시작 노드의 최단 경로 = 0 이다.
    pq.emplace(0, start);
    dist_arr[start] = 0;

    while (!pq.empty())
    {
        // 가장 최단 거리가 짧은 노드의 정보
        // (우선순위 큐가 최단 거리가 짧은 순으로 정렬해준다.)
        // (우선순위 큐가 현재 내림차순이므로 거리 * -1 의 과정을 거친다.)
        int dist = -pq.top().first;
        int now_v1 = pq.top().second;
        pq.pop();

        // 현재 노드의 dist가 dist_arr에 저장된 현재 노드의 최단 경로보다 길다면
        // 이미 최단 경로를 앞서 찾았던 것이므로 건너뛴다.
        if (dist_arr[now_v1] < dist)
            continue;

        // 현재 노드가 미방문했던 노드라면
        // 현재 노드와 인접한(연결된) 노드들을 탐색
        for (int i = 0; i < graph[now_v1].size(); i++)
        {
            int cost = dist + graph[now_v1][i].second;
            int now_v2 = graph[now_v1][i].first;

            // now_v1과 now_v2 사이의 기존 최단 경로(dist_arr[now_v2])가
            // 새로운 최단경로(cost)보다 길다면 갱신
            if (cost < dist_arr[now_v2])
            {
                dist_arr[now_v2] = cost;
                pq.emplace(-cost, now_v2);
            }
        }
    }
}

int main()
{
    int V, E;
    // 노드 갯수 >> 간선 갯수
    cin >> V >> E;

    int start;
    // 시작 노드
    cin >> start;

    // 노드의 갯수만큼 할당(노드 번호 1부터 시작)
    vector<vector<pair<int, int>>> graph(V + 1);

    for (int i = 0; i < E; i++)
    {
        int v1, v2, cost;
        cin >> v1 >> v2 >> cost;

        // v1 에서 v2 로 가는 비용 = cost
        graph[v1].emplace_back(v2, cost);
    }

    // 노드 사이의 최단 거리의 초기값은 무한대로 설정
    fill(dist_arr, dist_arr + 100001, MAX);

    Dijkstra(graph, start);

    // ---------------Print-------------------
    cout << "start node: " << start << endl;
    for (int i = 1; i <= V; i++)
    {
        cout << "node: " << i << ", ";

        cout << "dist: ";
        if (dist_arr[i] == MAX)
            cout << "INF" << endl;
        else
            cout << dist_arr[i] << endl;
    }
}

/*
<입력 예제>
6 11 1
1 2 2
1 3 5
1 4 1
2 4 2
2 3 3
3 2 3
3 6 5
4 3 3
4 5 1
5 3 1
5 6 2
*/