#include <string>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int GCD(int a, int b)
{
    int imax = max(a,b);
    int imin = min(a,b);
    
    int r = imax % imin;
    
    if( r == 0)
        return imin;
    else 
        return GCD(imin, r);
}
 
int solution(vector<int> arr) {
    int answer = arr[0];
    
    for(int i = 1; i < arr.size(); i++)
    {
        int gcd = GCD(answer, arr[i]);
        int lcm = answer * arr[i] / gcd;
        answer = lcm;
    }
    return answer;
}