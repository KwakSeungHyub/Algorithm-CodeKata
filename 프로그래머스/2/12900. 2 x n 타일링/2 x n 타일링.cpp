#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    vector<long long> dp(n+1, 0);
    dp[1] = 1; dp[2] = 2; dp[3] = 3; dp[4] = 5;
    for (int i=5; i<=n; i++) dp[i] = (dp[i-1] + dp[i-2]) % 1000000007;
    return dp[n];
}