#include <string>
#include <vector>
#include <bitset>
using namespace std;

void decodeNum(int n, vector<string>& map, vector<int>& arr) {
    for (int i=0; i<n; i++) {
        string decoded = bitset<16>(arr[i]).to_string().substr(16-n);// 숫자를 2진수로 변환하고 크기에 맞게 잘라준다.
        for (int j=0; j<n; j++) {
            if (decoded[j] == '1') map[i][j] = '#';// '1'이면 #을 찍어준다.
        }
    }
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer(n, string(n, ' '));
    decodeNum(n, answer, arr1);
    decodeNum(n, answer, arr2);
    return answer;
}