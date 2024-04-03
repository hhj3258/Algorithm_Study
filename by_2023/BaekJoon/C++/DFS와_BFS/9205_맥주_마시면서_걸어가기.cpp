#include <bits/stdc++.h>
using namespace std;

struct Point
{
    int x;
    int y;
};

int interDist(const Point &p1, const Point &p2)
{
    return abs(p1.x - p2.x) + abs(p1.y - p2.y);
}

bool visited[101];

void Solve(Point &home, Point &festival, vector<Point> &market)
{
    queue<Point> q;
    q.push(home);

    while (!q.empty())
    {
        Point now = q.front();
        q.pop();

        if (interDist(now, festival) <= 1000)
        {
            cout << "happy\n";
            return;
        }

        for (int i = 0; i < market.size(); i++)
        {
            if (visited[i] || interDist(now, market[i]) > 1000)
                continue;

            visited[i] = true;
            q.push(market[i]);
        }
    }

    cout << "sad\n";
}

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int market_num;
        cin >> market_num;

        Point home, festival;
        vector<Point> market(market_num);
        cin >> home.x >> home.y;
        for (int i = 0; i < market_num; i++)
            cin >> market[i].x >> market[i].y;
        cin >> festival.x >> festival.y;

        fill(visited, visited + market_num, false);
        Solve(home, festival, market);
    }
}