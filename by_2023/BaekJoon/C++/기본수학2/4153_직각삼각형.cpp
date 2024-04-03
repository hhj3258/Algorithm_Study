#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Tri
{
    int x, y, z;
};

int main()
{
    priority_queue<int, vector<int>, greater<int>> input;
    vector<Tri> triangles;
    int num;
    int zero_cnt = 0;

    for (int j = 0;; j++)
    {
        for (int i = 0; i < 3; i++)
        {
            cin >> num;
            input.push(num);

            if (num == 0)
                zero_cnt++;
            else
                zero_cnt = 0;
        }

        if (zero_cnt >= 3)
            break;

        triangles.push_back({-1, -1, -1});

        triangles[j].x = input.top();
        input.pop();
        triangles[j].y = input.top();
        input.pop();
        triangles[j].z = input.top();
        input.pop();
    }

    for (int i = 0; i < triangles.size(); i++)
    {
        int x = triangles[i].x;
        int y = triangles[i].y;
        int z = triangles[i].z;

        if ((x * x + y * y) == (z * z))
            cout << "right";
        else
            cout << "wrong";

        cout << endl;
    }
}