#include <string>
#include <vector>
#include <map>

using namespace std;

int score[8] = {0, 3, 2, 1, 0, 1, 2, 3}; // 점수 처리를 위한 int형 배열

string solution(vector<string> survey, vector<int> choices) {
    string answer = ""; // 정답 제출용 변수
    map<char, int> surv_elm; // 설문 비교를 위한 맵

    for(int i =0; i<survey.size(); i++)
        surv_elm[survey[i][choices[i]/4]] += score[choices[i]]; // 설문비교를 위해 설문지의 내용과 선택의 값을 합쳐 맵에 삽입

    answer += surv_elm['R'] >= surv_elm['T'] ? "R" : "T"; // 3항 연산자를 통해 맵에 삽입 될 문자열 골라내기
    answer += surv_elm['C'] >= surv_elm['F'] ? "C" : "F";
    answer += surv_elm['J'] >= surv_elm['M'] ? "J" : "M";
    answer += surv_elm['A'] >= surv_elm['N'] ? "A" : "N";

    return answer;
}