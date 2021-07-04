//백준 10757 : 큰 수 A+B
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    vector<char> vec_in_num1, vec_in_num2;
    string str_in_num1, str_in_num2;

    // 두가지 인풋을 ' '을 기준으로 잘라서 str로 받아줌
    getline(cin, str_in_num1, ' ');
    getline(cin, str_in_num2);

    //받아준 str 인풋의 각 길이를 저장
    int str1_size = str_in_num1.size();
    int str2_size = str_in_num2.size();

    //입력값의 벡터 컴포넌트화
    for (int i = 0; i < str1_size; i++)
        vec_in_num1.push_back(str_in_num1[i]);
    for (int i = 0; i < str2_size; i++)
        vec_in_num2.push_back(str_in_num2[i]);

    //long_length = 2가지 인풋 중 긴 것을 저장
    int long_length = 0;
    if (str1_size > str2_size)
        long_length = str1_size;
    else
        long_length = str2_size;

    vector<char>::iterator it;
    //this_length = 2가지 인풋 중 짧은 것을 저장
    int this_length = 0;

    //2가지 인풋의 전체 길이를 temp 값 0을 삽입하여 long_length에 맞춤
    if (long_length > str1_size)
    {
        this_length = long_length - str1_size;
        for (int i = 0; i < this_length; i++)
        {
            it = vec_in_num1.begin();
            vec_in_num1.insert(it, '0');
        }
    }
    else if (long_length > str2_size)
    {
        this_length = long_length - str2_size;
        for (int i = 0; i < this_length; i++)
        {
            it = vec_in_num2.begin();
            vec_in_num2.insert(it, '0');
        }
    }

    int* p_result_arr = new int[long_length];
    int int_temp1, int_temp2;

    //char 벡터를 int로 형변환하고 두 인풋 값을 더해줌
    //p_result_arr[i] = vec_in_num[i] + vec_in_num2[i]
    for (int i = 0; i < long_length; i++)
    {
        int_temp1 = vec_in_num1[i] - '0';
        cout << int_temp1 << endl;
        int_temp2 = vec_in_num2[i] - '0';
        cout << int_temp2 << endl;
        p_result_arr[i] = int_temp1 + int_temp2;
        cout << p_result_arr[i] <<endl<<endl;
    }

    //p_result_arr 배열 인덱스 중 10 이상인 인덱스의 경우 반올림
    //배열 0번째 인덱스의 경우 반올림 연산을 해줄 필요가 없음
    for (int i = long_length - 1; i > 0; i--)
    {
        if (p_result_arr[i] > 9)
        {
            p_result_arr[i] -= 10;
            p_result_arr[i - 1] += 1;
        }
    }

    //전체 숫자 길이인 long_length만큼 출력
    for (int i = 0; i < long_length; i++)
        cout << p_result_arr[i];

    return 0;
}