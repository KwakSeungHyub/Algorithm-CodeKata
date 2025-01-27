#include <string>
#include <vector>
using namespace std;

vector<double> solution(int k, vector<vector<int>> ranges)
{
    vector<double> answer;
    vector<pair<int,int>> v;//우박수열 그래프 벡터{인덱스, 수열 값}
    v.push_back({0,k});
    for(int i=1;k!=1;i++)
    {// 우박수열 구하는 부분
        if(k%2) k = 3*k +1;
        else k /=2;
        v.push_back({i, k});
    }
    for(auto c : ranges)
    {
        int s = c[0], e = v.size()-1+c[1];//시작 끝 인덱스 설정
        double res = 0;
        for(int i=s;i<e;i++)//넓이 구하는 부분
            res += (double)(v[i].second+v[i+1].second)/2;
        if (s>e) answer.push_back(-1.0);//시작 이 끝보다 크다면
        else answer.push_back(res);
    }
    return answer;
}