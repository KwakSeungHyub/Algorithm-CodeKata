#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(string my_string) {
    vector<string> answer;

    // 모든 접미사를 찾아서 벡터에 저장
    for (int i = 0; i < my_string.length(); i++) {
        answer.push_back(my_string.substr(i));
    }

    // 벡터를 사전순으로 정렬
    sort(answer.begin(), answer.end());

    return answer;
}