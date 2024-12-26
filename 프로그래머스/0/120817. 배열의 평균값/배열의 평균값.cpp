#include <string>
#include <vector>

using namespace std;

double solution(vector<int> numbers) {
    double answer = 0;
    int a = 0;
    for(int i = 0; i < numbers.size(); i++) {
       a += numbers[i];
    }
    answer = (double)a / numbers.size();
    return answer;
}