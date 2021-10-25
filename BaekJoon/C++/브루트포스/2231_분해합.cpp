#include <iostream>
#include <string>
using namespace std;

void Decompose_sum(int n)
{
    string str_n = to_string(n);
    int digits = str_n.size();
    int inc_num = n - 9 * digits;
    int answer = 0;

    for (inc_num; inc_num <= n; inc_num++)
    {
        string str_inc_num = to_string(inc_num);
        int temp = inc_num;

        for (int i = 0; i < str_inc_num.size(); i++)
            temp += (str_inc_num[i] - '0');

        if (temp == n)
        {
            answer = inc_num;
            break;
        }
    }

    cout << answer << endl;
}

int main()
{
    int n;
    cin >> n;

    Decompose_sum(n);
}