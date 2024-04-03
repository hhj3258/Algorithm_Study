#include <bits/stdc++.h>
using namespace std;

/*
주어지는 값 :

1. 스킬을 사용하기위해 위치해있는 마우스 좌표 int x,y

2. 스킬의 길이(반지름) int r

3. 각도(만약 60도면, 중심선으로부터 시계방향으로 60도, 반시계방향으로 60도.. 따라서 최대 스킬범위는 120도..) int d

4. 적들의 위치 xn, yn이 담긴 int형 2중벡터 vector<vector<int> > target
*/

#define PI 3.1415926535

// 벡터의 길이(크기)
double GetDistance(double x, double y)
{
    return sqrt(x * x + y * y);
}

// 두 벡터의 내적
double InnerProduct(double x1, double y1, double x2, double y2)
{
    return (x1 * x2 + y1 * y2);
}

// 라디안 -> 디그리
// degree = rad * (180 / PI)
double RadToDeg(double rad)
{
    return rad * 180 / PI;
}

void Solve(int x, int y, int r, int degree, vector<pair<int, int>> &target)
{
    // 1) 주어진 길이 r 보다 멀리 있는 target을 제외
    vector<pair<int, int>> inTarget;
    for (int i = 0; i < target.size(); i++)
    {
        if (GetDistance(target[i].first, target[i].second) <= r)
        {
            inTarget.push_back(target[i]);
        }
    }

    // 2) r 보다 길이가 작은 target들 탐색
    for (int i = 0; i < inTarget.size(); i++)
    {
        // 마우스 벡터와 target 벡터 내적
        double innerProduct = InnerProduct(x, y, inTarget[i].first, inTarget[i].second);

        // 마우스 벡터 크기
        double dist1 = GetDistance(x, y);
        // target 벡터 크기
        double dist2 = GetDistance(inTarget[i].first, inTarget[i].second);

        // theta = acos(두 벡터 내적 / 두 벡터 크기 곱)
        double theta = acos(innerProduct / (dist1 * dist2));
        double targetDegree = RadToDeg(theta);

        if (targetDegree <= degree)
        {
            cout << "lock on target: ";
            cout << inTarget[i].first << ", " << inTarget[i].second << endl;
        }
    }
}

int main()
{
    int x, y;
    // cin >> x >> y;
    x = 0;
    y = 1;

    int r;
    // cin >> r;
    r = 3;

    // ex) 정면 기준 왼쪽으로 60도, 오른쪽으로 60도
    int degree;
    // cin >> degree;
    degree = 60;

    vector<pair<int, int>> target(4);
    target.push_back(make_pair<int, int>(3, 1));  // 안들어옴
    target.push_back(make_pair<int, int>(-1, 2)); // 들어옴
    target.push_back(make_pair<int, int>(-1, 1)); // 들어옴
    target.push_back(make_pair<int, int>(0, 3));  // 들어옴

    Solve(x, y, r, degree, target);
}