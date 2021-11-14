#include <bits/stdc++.h>
using namespace std;

// 부모 노드를 찾는 함수
int getParent(int parent[], int x)
{
    if (parent[x] == x)
        return x;

    return parent[x] = getParent(parent, parent[x]);
}

// 두 부모 노드를 합치는 함수
void unionParent(int parent[], int a, int b)
{
    // 각 노드의 부모 값을 넣어준다
    a = getParent(parent, a);
    b = getParent(parent, b);

    // 더 작은 값이 큰 값의 부모 노드가 된다
    if (a < b)
        parent[b] = a;
    else
        parent[a] = b;
}

// 같은 부모를 가지는지 확인
int findParent(int parent[], int a, int b)
{
    // 각 노드의 부모 값을 넣어준다
    a = getParent(parent, a);
    b = getParent(parent, b);

    if (a == b)
        return true;
    else
        return false;
}

int main()
{
    int parent[11];

    // 독립된 노드들을 10개 생성
    for (int i = 1; i < 11; i++)
        parent[i] = i;

    unionParent(parent, 1, 2);
    unionParent(parent, 2, 3);
    unionParent(parent, 3, 4);

    unionParent(parent, 5, 6);
    unionParent(parent, 7, 8);

    bool isGroup = findParent(parent, 1, 5);

    if (isGroup)
        cout << "그룹";
    else
        cout << "그룹이 아님";
}