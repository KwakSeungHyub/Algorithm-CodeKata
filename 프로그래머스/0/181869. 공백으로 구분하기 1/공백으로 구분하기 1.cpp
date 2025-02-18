#include <string>
#include <vector>

using namespace std;

vector<string> solution(string my_string) {
    vector<string> answer;
    string temp;
    
    for(int i = 0; i < my_string.size(); i++) {
        if(my_string[i] != ' ') temp += my_string[i]; // 공백이 아닐경우 임시 문자열에 값 추가
        else {
            answer.push_back(temp); // 공백이 있을경우 answer 뒤에 밀어넣기
            temp = ""; // 임시 문자열 초기화
        }
    }
    answer.push_back(temp);
    return answer;
}