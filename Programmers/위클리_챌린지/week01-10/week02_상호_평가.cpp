//과제물에 학점 부여(상호평가)
//[i, j]=i번 학생이 평가한 j번 학생의 점수
//0번 학생이 평가한 점수=[0,0~4]
//[0, 0]=0번 학생이 평가한 0번 학생의 점수
//[2, 2]=2번 학생이 평가한 2번 학생의 점수
//자기 자신을 평가한 점수가 유일한 최고점 or
//유일한 최저점이면 제외하고 평균 계산
//0번 학생 평균=([1,0]+[2,0]+[3,0]+[4,0])/4
//출력 예: "FBABD"

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

char Grade(float myScore)
{
    char myGrade;
    if (myScore >= 90)
        myGrade = 'A';
    else if (myScore >= 80)
        myGrade = 'B';
    else if (myScore >= 70)
        myGrade = 'C';
    else if (myScore >= 50)
        myGrade = 'D';
    else
        myGrade = 'F';

    return myGrade;
}

string solution(vector<vector<int>> scores)
{
    string answer = "";
    float aver[10] = {
        0,
    };
    for (int i = 0; i < scores.size(); i++)
    {
        vector<pair<int, int>> student(scores.size());

        for (int j = 0; j < scores.size(); j++)
            student[j] = (make_pair(scores[j][i], j));

        sort(student.begin(), student.end());

        if (student[0].second == i)
            if (student[0].first != student[1].first)
                student.erase(student.begin());

        if (student[student.size() - 1].second == i)
            if (student[student.size() - 1].first != student[student.size() - 2].first)
                student.erase(student.end());

        for (int j = 0; j < student.size(); j++)
            aver[i] += student[j].first;

        aver[i] /= student.size();
        answer += Grade(aver[i]);
    }

    return answer;
}

int main()
{
    vector<vector<int>> scores = {{100, 90, 98, 88, 65}, {50, 45, 99, 85, 77}, {47, 88, 95, 80, 67}, {61, 57, 100, 80, 65}, {24, 90, 94, 75, 65}};

    cout << solution(scores) << endl;
}