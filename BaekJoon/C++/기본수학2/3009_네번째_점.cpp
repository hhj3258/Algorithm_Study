#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

struct XY
{
    int x, y;
};

int main()
{
    vector<XY> xy(3);
    map<int, int> x_map;
    map<int, int> y_map;

    for (int i = 0; i < xy.size(); i++)
    {
        cin >> xy[i].x;
        x_map[xy[i].x]++;
        cin >> xy[i].y;
        y_map[xy[i].y]++;
    }

    for (auto iter = x_map.begin(); iter != x_map.end(); iter++)
    {
        if ((*iter).second == 1)
        {
            cout << (*iter).first << " ";
            break;
        }
    }

    for (auto iter = y_map.begin(); iter != y_map.end(); iter++)
    {
        if ((*iter).second == 1)
        {
            cout << (*iter).first;
            break;
        }
    }
}