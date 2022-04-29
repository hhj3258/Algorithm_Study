#include <bits/stdc++.h>
using namespace std;

#define PI 3.1415926535

struct Circle
{
public:
    Circle(double _x, double _y, double _r) : x(_x), y(_y), r(_r)
    {
    }

    double x;
    double y;
    double r;
};

double InterCircleDistance(Circle c1, Circle c2)
{
    return sqrt(pow(c2.y - c1.y, 2) + pow(c2.x - c1.x, 2));
}

double Solve(Circle c1, Circle c2)
{
    if (c2.r > c1.r)
    {
        Circle temp = c1;
        c1 = c2;
        c2 = temp;
    }

    double interDist = InterCircleDistance(c1, c2);

    if (interDist >= (c1.r + c2.r)) // 두 원이 겹치지 않을 때
    {
        return 0;
    }
    else if (c2.r + interDist <= c1.r) // 한 원이 다른 원의 내부에 있을 때
    {
        return (c2.r * c2.r * PI);
    }
    else // 두 원이 부분적으로 겹칠 때
    {
        // 사잇각
        double c1_theta = 2 * acos((c1.r * c1.r + interDist * interDist - c2.r * c2.r) / (2 * c1.r * interDist));
        double c2_theta = 2 * acos((c2.r * c2.r + interDist * interDist - c1.r * c1.r) / (2 * c2.r * interDist));

        // 부채꼴 넓이
        double c1_S = (c1.r * c1.r) * c1_theta / 2;
        double c2_S = (c2.r * c2.r) * c2_theta / 2;

        // 이등변 삼각형 넓이
        double c1_A = (c1.r * c1.r) * sin(c1_theta) / 2;
        double c2_A = (c2.r * c2.r) * sin(c2_theta) / 2;

        double answer = (c1_S - c1_A) + (c2_S - c2_A);
        return answer;
    }
}

int main()
{
    cout << fixed;
    cout.precision(3);

    double x1, y1, r1;
    cin >> x1 >> y1 >> r1;
    Circle c1(x1, y1, r1);

    double x2, y2, r2;
    cin >> x2 >> y2 >> r2;
    Circle c2(x2, y2, r2);

    cout << Solve(c1, c2);
}