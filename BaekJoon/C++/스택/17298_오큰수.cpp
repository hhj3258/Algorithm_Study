#include <bits/stdc++.h>
using namespace std;

int N;

void Solve(vector<int> &A)
{
    stack<int> myStack;

    // 수열 A의 크기만큼 반복
    for (int i = 0; i < N; i++)
    {
        // 스택이 비어있지 않고, A[myStack.top()]이 A[i]보다 작을 때
        while (!myStack.empty() && A[myStack.top()] < A[i])
        {
            A[myStack.top()] = A[i];
            myStack.pop();
        }

        // 그 외의 경우에는 인덱스 i 를 스택에 push
        myStack.push(i);
    }

    // 오큰수를 찾지 못한 원소는 -1로 변경
    while (!myStack.empty())
    {
        A[myStack.top()] = -1;
        myStack.pop();
    }

    for (int i = 0; i < N; i++)
        cout << A[i] << ' ';
}

int main()
{
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];

    Solve(A);
}