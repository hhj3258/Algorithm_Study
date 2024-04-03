#include <bits/stdc++.h>
using namespace std;

struct Point
{
    long long x = 0;
    long long y = 0;
};

// 반시계방향이면 양수, 시계방향이면 음수
int CCW(Point p1, Point p2, Point p3)
{
    long long a = p1.x * p2.y + p2.x * p3.y + p3.x * p1.y;
    long long b = p2.x * p1.y + p3.x * p2.y + p1.x * p3.y;

    if (a - b < 0)
        return -1;
    else
        return 1;
}

bool Solve(vector<Point> &L1, vector<Point> &L2)
{
    int ABC = CCW(L1[0], L1[1], L2[0]);
    int ABD = CCW(L1[0], L1[1], L2[1]);

    int CDA = CCW(L2[0], L2[1], L1[0]);
    int CDB = CCW(L2[0], L2[1], L1[1]);

    // 둘 모두 음수여야 교차한 것
    if (ABC * ABD < 0 && CDA * CDB < 0)
        return true;
    else
        return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<Point> L1(2);
    vector<Point> L2(2);

    for (int i = 0; i < 2; i++)
        cin >> L1[i].x >> L1[i].y;
    for (int i = 0; i < 2; i++)
        cin >> L2[i].x >> L2[i].y;

    bool isCross = Solve(L1, L2);
    if (isCross)
        cout << 1;
    else
        cout << 0;
}