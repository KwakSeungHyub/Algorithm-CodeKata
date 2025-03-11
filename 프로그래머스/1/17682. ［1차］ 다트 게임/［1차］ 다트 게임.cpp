#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    vector<string> dart;
    vector<int> score;
    string text="";
    int temp, score_index;
    
    for (int i = 0; i < dartResult.size(); i++) //문자열을 하나씩 문자열형 vector에 저장
    {
        if( dartResult[i] =='1' && dartResult[i+1] == '0')
        {
            dart.push_back("10");
            i++;
        }
        else
        {
            text = dartResult[i];
            dart.push_back(text);
        }
    }
    
    for(int i = 0; i < dart.size(); i++)
    {
        score_index = score.size()-1; //score vector의 인덱스 변수
        
        //얻는 점수
        if(dart[i] >= "0" && dart[i] <= "9" ||dart[i] =="10")
            score.push_back( stoi(dart[i]) );
        //영역 당첨
        else if(dart[i] == "D")
        {
            temp = pow(score[score_index] ,2);
            score[score_index] = temp;
        }
        else if(dart[i] == "T")
        {
            temp = pow(score[score_index] ,3);
            score[score_index] = temp;
        }
        //보너스
        else if (dart[i] == "*" || dart[i] == "#")
        {
            if (dart[i] == "*")
            {
                if ( score.size() == 1) // 첫 번째 기회에 나온 경우
                    score[score_index] *= 2;
                else
                {
                    score[ score_index ] *=2;
                    score[ score_index-1 ] *=2;
                }
            }
            else if ( dart[i] == "#")
                score[ score_index ] = -score[ score_index ];
        }
    }
    
    for(int i = 0 ;i < score.size();i++)
        answer+=score[i];
    return answer;
}