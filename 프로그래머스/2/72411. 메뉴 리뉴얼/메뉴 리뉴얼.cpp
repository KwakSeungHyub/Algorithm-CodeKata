#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

unordered_map<string,int> m;

void dfs(int idx, string tmp, string order) {
    if (tmp.size() > order.size()) {
        return ;
    }
    m[tmp]++;
    for (int i = idx; i < order.size(); i++) {
        dfs(i+1, tmp+order[i], order);
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    for (auto order : orders) {
        sort(order.begin(), order.end());//order가 정렬이 안되어있기 때문에 정렬
        dfs(0, "", order);// 조합할 수 있는 모든 메뉴를 m에 넣어준다.
    }
    for (auto setSize : course) {
        int mostOrdered = 0;// 가장 많이 선택된 횟수를 저장
        for (auto menu : m) {
            if (menu.first.size() == setSize)// 코스의 사이즈를 만족하면서 가장 많이 선택된 횟수 갱신
                mostOrdered = max(mostOrdered, menu.second);
        }
        if (mostOrdered <= 1) continue;// 횟수가 최소 2이상이어야한다.
        for (auto menu : m) {
            if (menu.first.size() == setSize && menu.second == mostOrdered)
                answer.push_back(menu.first);// 조건에 부합한다면 넣어준다.
        }
    }
    sort(answer.begin(),answer.end());// 사전순으로 정렬
    return answer;
}