#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const string &x, const string &y) {
    return x+y > y+x;
}

string solution(vector<int> numbers) {
    string answer = "";
    int N = numbers.size();
    
    // string으로 변환
    vector<string> strings;
    for (int i=0; i<N; i++) {
        strings.push_back(to_string(numbers[i]));
    }

    // 정렬 (cmp 함수 : 숫자 두 개씩 이어붙인 값 비교)
    sort(strings.begin(), strings.end(), cmp);

    // 정렬한 순서대로 숫자 이어붙여서 answer 값 구하기
    for (int i=0; i<N; i++) {
        answer += strings[i];
    }

    // 주어진 numbers에서 가장 큰 값이 0인 경우 answer = '0' 처리
    if (answer[0] == '0') {
        answer = '0';
    }

    return answer;
}