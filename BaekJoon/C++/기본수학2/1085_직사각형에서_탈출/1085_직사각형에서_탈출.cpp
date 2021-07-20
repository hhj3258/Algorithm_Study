#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> xywh(4);
    for (int i = 0; i < xywh.size(); i++)
        cin >> xywh[i];

    vector<int> dist(4);
    dist[0] = xywh[3] - xywh[1];
    dist[1] = xywh[2] - xywh[0];
    dist[2] = xywh[0];
    dist[3] = xywh[1];

    cout << *min_element(dist.begin(), dist.end());
}