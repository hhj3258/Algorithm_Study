#include <iostream>
#include <vector>
using namespace std;

string equation;

void Solve()
{
    bool minus_flag = false;
    int sum_temp = 0;
    string num_temp = "";

    for (int i = 0; i <= equation.size(); i++)
    {
        if (equation[i] == '-' || equation[i] == '+' || i == equation.size())
        {
            if (minus_flag)
            {
                sum_temp -= stoi(num_temp);
                num_temp = "";
            }
            else
            {
                sum_temp += stoi(num_temp);
                num_temp = "";
            }
        }
        else
        {
            num_temp += equation[i];
            continue;
        }

        if (equation[i] == '-')
            minus_flag = true;
    }

    cout << sum_temp;
}

int main()
{
    cin >> equation;
    Solve();
}