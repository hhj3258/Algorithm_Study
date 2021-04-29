#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<char> in_num1, in_num2;

    string temp, temp2;

    getline(cin, temp, ' ');
    getline(cin, temp2);

    int temp_size = temp.size();
    int temp2_size = temp2.size();

    ///////////////////입력값의 벡터 컴포넌트화///////////////////////
    for (int i = 0; i < temp_size; i++)
        in_num1.push_back(temp[i]);

    for (int i = 0; i < temp2_size; i++)
        in_num2.push_back(temp2[i]);

    int long_length = 0;
    if (temp_size > temp2_size)
        long_length = temp_size;
    else
        long_length = temp2_size;

    vector<char>::iterator it;
    if (long_length > temp_size)
    {
        int this_len = long_length - temp_size;
        for (int i = 0; i < this_len; i++)
        {
            it = in_num1.begin();
            in_num1.insert(it, '0');
        }
    }
    else if (long_length > temp2_size)
    {
        int this_len = long_length - temp2_size;
        for (int i = 0; i < this_len; i++)
        {
            it = in_num2.begin();
            in_num2.insert(it, '0');
        }
    }

    /////////////////////////////////////////////////
    int* int_arr = new int[long_length];
    int int_temp1, int_temp2;

    for (int i = 0; i < long_length; i++)
    {
        int_temp1 = in_num1[i] - '0';
        int_temp2 = in_num2[i] - '0';
        int_arr[i] = int_temp1 + int_temp2;
    }

    for (int i = long_length - 1; i >= 1; i--)
    {
        if (int_arr[i] >= 10)
        {
            int_arr[i] -= 10;
            int_arr[i - 1] += 1;
        }
    }

    for (int i = 0; i < long_length; i++)
        cout << int_arr[i];

    return 0;
}