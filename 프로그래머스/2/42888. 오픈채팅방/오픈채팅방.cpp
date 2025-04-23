#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    string message[2] = {"님이 들어왔습니다.", "님이 나갔습니다."};
    vector<pair<string, int>> order;// 들어오고 나간 순서를 저장
    unordered_map<string, string> id_name;// uid를 기반으로 닉네임 저장
    
    for (auto r : record) {
        string cmd, uid, name;
        istringstream iss(r);// 입력 스트림으로 받아준다.(공백을 기준으로 나눠줄 때 유용)
        iss >> cmd;
        if (cmd == "Enter") {
            iss >> uid >> name;
            order.push_back({uid, 0});// 출입 순서에 uid로 저장
            id_name[uid] = name;// uid 닉네임 저장
        } else if (cmd == "Leave") {
            iss >> uid;
            order.push_back({uid, 1});// 출입 순서에 uid로 저장
        } else {
            iss >> uid >> name;
            id_name[uid] = name;// uid 닉네임 갱신
        }
    }
    for (auto o : order) {
    	// 출입순서의 uid에 맞춰 닉네임 + 행동을 넣어준다.
        answer.push_back(id_name[o.first] + message[o.second]);
    }
    return answer;
}