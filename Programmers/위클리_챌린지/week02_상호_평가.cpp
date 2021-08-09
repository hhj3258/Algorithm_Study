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

    for (int k = 0; k < scores.size(); k++)
    {
        int minV = 101;
        int maxV = -1;
        for (int i = 0; i < scores.size(); i++)
        {
            if (scores[i][k] < minV)
                minV = scores[i][k];
            if (scores[i][k] > maxV)
                maxV = scores[i][k];
        }

        int onlyN = 0;
        for (int i = 0; i < scores.size(); i++)
        {
            if (scores[i][k] == minV)
                onlyN++;
            if (scores[i][k] == maxV)
                onlyN++;
        }

        int divN = 0;
        for (int i = 0; i < scores.size(); i++)
        {
            if (i == k && onlyN == 1)
                continue;

            aver[k] += scores[i][k];
            divN++;
        }

        aver[k] /= divN;
        answer += Grade(aver[k]);
    }

    return answer;
}

int main()
{
    vector<vector<int>> scores = {{100, 90, 98, 88, 65}, {50, 45, 99, 85, 77}, {47, 88, 95, 80, 67}, {61, 57, 100, 80, 65}, {24, 90, 94, 75, 65}};

    cout << solution(scores) << endl;
}