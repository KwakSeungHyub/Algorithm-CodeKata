#include <string>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

int solution(int cacheSize, vector<string> cities)
{
    int answer = 0;
    deque<string> dq;
    for(auto city : cities)
    {
        bool cache = false;//캐시로 있는지 없는지
        for(int i=0;i<city.size();i++)//도시이름 소문자로 변환
            if(isupper(city[i])) city[i] += 32;
        for(int i=0;i<dq.size();i++)
        {
            if (dq[i] == city)
            {//캐시에 해당 도시가 있다면
                cache = true;
                dq.erase(dq.begin()+i);//해당 도시 dq에서 삭제
                dq.push_front(city);//갱신
                answer += 1;
            }
        }
        if (!cache)
        {//캐시에 없다면
            dq.push_front(city);
            if (dq.size() > cacheSize) dq.pop_back();
            answer += 5;
        }
    }
    return answer;
}