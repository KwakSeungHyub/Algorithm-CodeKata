#include <string>
#include <vector>

using namespace std;

int solution(int num1, int num2) {
    int answer = 0;
    double dev = (double)num1 / (double)num2;
    answer = dev * 1000;
    return answer;
}