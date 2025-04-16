#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> sepString(const string& s) {
    vector<string> res;

    int head = 0;
    while (!isdigit(s[head])) head++;// 첫 숫자 찾을때까지 밀어준다.
    res.push_back(s.substr(0, head));// 숫자 전까지가 head
    res.push_back(s.substr(head, 5));// 숫자부터 최대 5개가 number가 될수있는 범위
    // tail은 사실상 생각하지 않아도 되는 부분이다.
    for (int i=0; i<head; i++) {// 대소문자 동일하게 내려준다.
        res[0][i] = tolower(res[0][i]);
    }
    return res;
}

bool compare(const string& a, const string& b) {
    vector<string> a_part, b_part;
    a_part = sepString(a);
    b_part = sepString(b);
    if (a_part[0] != b_part[0]) {// head 사전순 정렬
        return a_part[0] < b_part[0];
    } 
    return stoi(a_part[1]) < stoi(b_part[1]);// 정수로 바꿨을때 오름차순, 동일하다면 들어온 순서대로 리턴
}

vector<string> solution(vector<string> files) {
    stable_sort(files.begin(), files.end(), compare);
    return files;
}