#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    int size = msg.size(), idx = 27;// 알파벳 26 이후부터 인덱스 추가
    unordered_map<string, int> um;// 새로운 인덱스 넣을 곳

    for (int i=0; i<size;) {
        string w = msg.substr(i, 1);
        int j = i+1;
        for (; j<size; j++) {
            if (um[w + msg[j]] == 0) {// 인덱스에 없다면
                um[w + msg[j]] = idx++;// 인덱스 추가
                break ;
            }
            w += msg[j];//문자열 늘려줌
        }
        if (w.size() == 1) answer.push_back(w[0] - 'A' + 1);// 길이가 1일떄 인덱스 구해주기
        else answer.push_back(um[w]);// 인덱스 넣어 놓은것 값으로
        i = j;
    }
    return answer;
}