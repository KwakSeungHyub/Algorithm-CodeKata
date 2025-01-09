#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<int> topping)
{
    int answer = 0, cake;
    unordered_map <int,int> base, cmp;// base: 안잘린 통짜 케이크, cmp: 잘랐을때의 상태
    for(auto c : topping) base[c]++;
    cake = base.size();// 케이크에 올라간 토핑의 총 개수
    for(auto c : topping)
    {// 한 토핑씩 잘라준다.
        cmp[c]++; base[c]--;
        if (base[c] == 0 ) cake--;// 해당 토핑의 개수가 떨어지면 안자른 케이크 토핑수--
        if (cake == cmp.size()) answer++;// 안자른 케이크 토핑수 == 자른 케이크 토핑수 이면
    }
    return answer;
}