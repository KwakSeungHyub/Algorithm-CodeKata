#include <vector>
#include <unordered_map>
using namespace std;

vector<int> solution(string s) {
    unordered_map<int, int> m;
    for (int i=2; i<s.size(); i++) {
        if (isdigit(s[i])) {// 숫자면
            m[stoi(s.substr(i))]++;// 정수로 바꿔준값을 맵에 ++해준다.
            while (isdigit(s[i]))// 숫자 아닐때까지 밀어준다.
                i++;
        }
    }
    int size = m.size();// 등장하는 수의 개수
    vector<int> answer(size);
    for (auto c : m) answer[size - c.second] = c.first;// size - c.second 가 곧 인덱스이다.
    return answer;
}