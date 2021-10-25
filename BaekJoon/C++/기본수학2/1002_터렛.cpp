#define _USE_MATH_DEFINES

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    int T;
    int x1, y1, r1;
    int x2, y2, r2;

    cin >> T;
    vector<int> answer(T);

    for (int i = 0; i < T; i++)
    {
        cin >> x1 >> y1 >> r1;
        cin >> x2 >> y2 >> r2;

        double AB = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

        int min_r = min(r1, r2);
        int max_r = max(r1, r2);

        if (AB == 0)
        {
            if (r1 != r2)
                answer[i] = 0;
            else
                answer[i] = -1;
        }
        else if (r1 + r2 > AB)
        {
            if (AB + min_r == max_r)
                answer[i] = 1;
            else if (AB + min_r < max_r)
                answer[i] = 0;
            else
                answer[i] = 2;
        }
        else if (r1 + r2 < AB)
            answer[i] = 0;
        else
            answer[i] = 1;
    }

    for (int i : answer)
        cout << i << endl;
}