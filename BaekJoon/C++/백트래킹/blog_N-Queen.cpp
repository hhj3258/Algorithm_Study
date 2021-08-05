#include <iostream>
#include <vector>
using namespace std;

int N;          //입력: 1 ≤ N < 15
int answer = 0; //출력

//체스판 배열
vector<int> visited(15, -1);

// 유망한 조건 판단
// qCnt: 현재 배치한 퀸의 행
bool Check(int qCnt)
{
    // 0번째 행부터 qCnt 행까지 반복
    for (int i = 0; i < qCnt; i++)
    {
        // 배치했던 퀸들과 현재 배치하려는 퀸이 서로 공격할 수 있다면 return 0
        // 세로축(열) 판단: 현재 배치한 퀸의 열 == 배치했던 퀸의 열 ||
        // 대각축 판단:     현재 배치한 퀸의 행 - 배치했던 퀸의 행 == 절대값(현재 배치한 퀸의 열 - 배치했던 퀸의 열)
        if (visited[qCnt] == visited[i] || qCnt - i == abs(visited[qCnt] - visited[i]))
            return 0;
    }

    //현재 퀸을 배치할 수 있다면 return 1
    return 1;
}

void N_Queen(int qCnt)
{
    // 현재 배치한 퀸의 갯수가 입력값(N)과 같다면 탈출
    if (qCnt == N)
    {
        //출력(해답)++
        answer++;

        //케이스 테스트 출력
        cout << "<case " << answer << ">\n";
        for (int i = 0; i < visited.size(); i++)
        {
            if (visited[i] != -1)
                cout << "[" << i << ", " << visited[i] << "]\n";
        }
        cout << "\n";

        return;
    }

    // 0번째 행부터 N 행까지 반복
    for (int j = 0; j < N; j++)
    {
        // [qCnt, j] 에 배치해보고
        visited[qCnt] = j;

        // 배치할 수 있다면
        if (Check(qCnt))
            // 퀸의 행을 + 1 하고 다음 퀸을 배치해본다.
            N_Queen(qCnt + 1);
    }
}

int main()
{
    cin >> N;
    N_Queen(0);
    cout << "answer: " << answer;
}