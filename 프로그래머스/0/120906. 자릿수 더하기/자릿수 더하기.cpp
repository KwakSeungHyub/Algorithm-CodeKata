#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    while(n != 0) {
        answer = answer + n % 10;
        n = n / 10;
    }
    return answer;
}