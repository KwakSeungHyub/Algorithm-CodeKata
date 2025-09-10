#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    answer.push_back(n);  // 초기값 n을 answer에 추가합니다.
    
    while (n != 1) {
        if (n % 2 == 0) {
            n = n / 2;  // n이 짝수인 경우 2로 나눕니다.
        } else {
            n = 3 * n + 1;  // n이 홀수인 경우 3 * n + 1을 계산합니다.
        }
        answer.push_back(n);  // 변환된 값 n을 answer에 추가합니다.
    }
    return answer;
}