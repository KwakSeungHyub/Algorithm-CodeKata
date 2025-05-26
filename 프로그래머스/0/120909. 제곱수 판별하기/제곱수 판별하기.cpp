#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n) {
    int answer = sqrt(n);
    answer = (answer * answer == n)? 1:2;
    return answer;
}