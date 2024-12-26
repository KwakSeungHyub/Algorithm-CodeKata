#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string X, string Y)
{
    string answer = "";
    vector<int> v(10, 0);// 0~9까지 숫자 개수
    vector<char> res;
    for(int i=0;i<X.size();i++) v[X[i] - '0']++;//X 에 들어있는 숫자 각 v에 ++
    for(int i=0;i<Y.size();i++) if(--v[Y[i] - '0'] >= 0) res.push_back(Y[i]);// 0보다 크거나 같다면
    sort(res.begin(), res.end(), greater<char>());//내림차순 정렬
    for(auto c : res) answer.push_back(c);
    if (answer.empty()) return "-1";//하나도 같은게 없다면
    if (answer[0] == '0') return "0";//0으로만 이루어진 문자열 이라면
    return answer;
}