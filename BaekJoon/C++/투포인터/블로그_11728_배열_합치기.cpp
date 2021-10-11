#include <bits/stdc++.h>
using namespace std;

int N, M;

void TwoPointer(vector<int> &A, vector<int> &B)
{
    // 배열 A와 B 정렬
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int ptrA = 0; // 배열 A 포인터
    int ptrB = 0; // 배열 B 포인터

    // answer: A배열과 B배열을 합쳐줄 배열
    vector<int> answer(N + M);
    // 배열 answer 포인터(인덱스로 봐도 무방함)
    int idx = 0;

    //배열 A 포인터가 N보다 작고 배열 B 포인터가 M보다 작을 때까지 반복
    while (ptrA < N && ptrB < M)
    {
        // A의 포인터의 값이 B의 포인터의 값보다 작다면
        if (A[ptrA] < B[ptrB])
        {
            // A 포인터의 값을 넣어준다
            answer[idx++] = A[ptrA];
            // A 포인터 + 1
            ptrA++;
        }
        // 그 외의 경우
        else
        {
            // B 포인터의 값을 넣어준다
            answer[idx++] = B[ptrB];
            // B 포인터 + 1
            ptrB++;
        }
    }

    // A 배열을 모두 탐색하지 못했다면
    while (ptrA < N)
        // A 배열의 값을 모두 넣어준다
        answer[idx++] = A[ptrA++];

    // B 배열을 모두 탐색하지 못했다면
    while (ptrB < M)
        // B 배열의 값을 모두 넣어준다
        answer[idx++] = B[ptrB++];

    for (int i : answer)
        cout << i << ' ';
}

int main()
{
    // 입력 속도 증가
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 배열 A 크기 >> 배열 B 크기
    cin >> N >> M;

    vector<int> A(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];

    vector<int> B(M);
    for (int i = 0; i < M; i++)
        cin >> B[i];

    TwoPointer(A, B);
}