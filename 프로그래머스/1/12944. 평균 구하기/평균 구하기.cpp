#include <string>
#include <vector>

using namespace std;

double solution(vector<int> arr) {
    double answer = 0;
    int a = 0;
    for(int i = 0; i < arr.size(); i++) {
        a += arr[i];
    }
    answer = (double) a / arr.size();
    return answer;
}