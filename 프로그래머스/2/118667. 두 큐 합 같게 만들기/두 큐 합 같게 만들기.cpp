#include <string>
#include <vector>
#include <numeric>
using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    long elem, sum1, sum2;
    int idx1 = 0, idx2 =0;
    int cnt = 0;
    
    int qSize = queue1.size();
    sum1 = accumulate(queue1.begin(), queue1.end(), 0);
    sum2 = accumulate(queue2.begin(), queue2.end(), 0);
    
    while (cnt <= qSize * 4){
        if(sum1==sum2) return cnt;
        else if(sum1<sum2){
            elem = idx2 < qSize? queue2[idx2]:queue1[idx2-qSize];
            sum2 -= elem;
            sum1 += elem;
            idx2++;
            cnt++;
        }
        else{
            elem = idx1 < qSize? queue1[idx1]:queue2[idx1-qSize];
            sum1 -= elem;
            sum2 += elem;
            idx1++;
            cnt++;
        }
    }

    return -1;
}