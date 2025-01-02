#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    bool inside = false;// 단어 안에 있는지 여부
    for(auto c : s) {
        if (c == ' ') { // 공백이면 이제 곧 첫번째 단어가 온다는 의미이기 때문에 false 입력 및 공백 입력
            answer += ' ';
            inside = false;
        } else if (!inside) {// 단어 첫번째이면
            answer += toupper(c);
            inside = true;
        } else {
            answer += tolower(c);
        }
    }
    return answer;
}