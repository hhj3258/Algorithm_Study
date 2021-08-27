#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string new_id)
{

    for (int i = 0; i < new_id.size(); i++)
    {
        //1단계 new_id의 모든 대문자를 대응되는 소문자로 치환합니다.
        if (new_id[i] >= 'A' && new_id[i] <= 'Z')
        {
            new_id[i] = new_id[i] + 32;
            continue;
        }

        //2단계 new_id에서 알파벳 소문자, 숫자, 빼기(-), 밑줄(_), 마침표(.)를 제외한 모든 문자를 제거합니다.
        if ((new_id[i] >= 'a' && new_id[i] <= 'z') || (new_id[i] >= '0' && new_id[i] <= '9') || new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.')
        {
        }
        else
        {
            new_id.erase(new_id.begin() + i);
            i--;
            continue;
        }
    }

    //3단계 new_id에서 마침표(.)가 2번 이상 연속된 부분을 하나의 마침표(.)로 치환합니다.
    int dot_cnt = 0;
    for (int i = 0; i < new_id.size(); i++)
    {
        if (new_id[i] != '.')
            dot_cnt = 0;
        else if (new_id[i] == '.')
        {
            dot_cnt++;
            if (dot_cnt >= 2)
            {
                new_id.erase(new_id.begin() + i);
                i--;
            }
        }
    }

    //4단계 new_id에서 마침표(.)가 처음이나 끝에 위치한다면 제거합니다.
    if (new_id[0] == '.')
        new_id.erase(new_id.begin());
    if (new_id[new_id.size() - 1] == '.')
        new_id.erase(new_id.end() - 1);

    //5단계 new_id가 빈 문자열이라면, new_id에 "a"를 대입합니다.
    if (new_id.size() == 0)
        new_id += "a";

    //6단계 new_id의 길이가 16자 이상이면, new_id의 첫 15개의 문자를 제외한 나머지 문자들을 모두 제거합니다.
    //만약 제거 후 마침표(.)가 new_id의 끝에 위치한다면 끝에 위치한 마침표(.) 문자를 제거합니다.
    while (new_id.size() >= 16)
        new_id.pop_back();

    if (new_id[new_id.size() - 1] == '.')
        new_id.pop_back();

    //7단계 new_id의 길이가 2자 이하라면, new_id의 마지막 문자를 new_id의 길이가 3이 될 때까지 반복해서 끝에 붙입니다.
    while (new_id.size() <= 2)
        new_id += new_id[new_id.size() - 1];

    return new_id;
}

int main()
{
    string new_id1 = "...!@BaT#*..y.abcdefghijklm";
    string result = "bat.y.abcdefghi";

    string new_id2 = "=.=";
    string result2 = "aaa";

    string answer = solution(new_id2);

    cout << "answer: " << answer << endl;
    cout << "result: " << result2 << endl;

    if (answer == result2)
        cout << "통과";
    else
        cout << "다시";
}