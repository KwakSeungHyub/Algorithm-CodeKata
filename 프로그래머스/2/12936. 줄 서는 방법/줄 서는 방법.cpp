#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long f(int n) {
    long long result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

vector<int> solution(int n, long long k) {
    vector<int> answer;
    vector<int> line;
    
    for (int i = 1; i <= n; i++) {
        line.push_back(i);
    }
    
    while (1) {
        long long result = f(n - 1);
        int a = k / result;
        long long b = k % result;
        
        if (b == 0) {
            a--;
        }
        
        answer.push_back(line[a]);
        line.erase(line.begin() + a);
        
        if (b == 1) {
            for (int i = 0; i < line.size(); i++) {
                answer.push_back(line[i]);
            }
            return answer;
        }
        else if (b == 0) {
            for (int i = line.size() - 1; i >= 0; i--) {
                answer.push_back(line[i]);
            }
            return answer;
        }
        else {
            k = b;
            n--;
        }
    }
    
    return answer;
}
