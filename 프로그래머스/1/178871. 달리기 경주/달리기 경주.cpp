#include <string>
#include <vector>
#include <map>
using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;
    map<int, string> m1; // 등수와 선수 이름 맵
    map<string, int> m2; // 선수 이름과 등수 맵
     for(int i=0;i<players.size();i++) // player의 사이즈 만큼 진행
    {
        m1[i] = players[i]; // m1에 현재 순위를 저장
        m2[players[i]] = i; // m2에도 저장
    }
    for(int i=0;i<callings.size();i++) // 해설진의 호출 순위 맵
    {
        int cur_idx = m2[callings[i]];//호출 선수 이름, 순위
        string change = m1[cur_idx - 1];//앞선 선수 이름, 순위
        m1[cur_idx - 1] = callings[i]; //
        m1[cur_idx] = change;
        m2[callings[i]] = cur_idx - 1;
        m2[change] = cur_idx;
    }
    for(auto c : m1) answer.push_back(c.second);
    return answer;
}