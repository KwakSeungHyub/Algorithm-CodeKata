#include <string>
#include <vector>
using namespace std;

string solution(string new_id) {
    for (int i=0; i<new_id.size(); i++) {
        if (isupper(new_id[i])) new_id[i] = tolower(new_id[i]);// 소문자로 변환
        else if (!isalnum(new_id[i]) && new_id[i] != '-' && new_id[i] != '_' && new_id[i] != '.') {
            new_id.erase(new_id.begin() + i--); // 허용 문자가 아니면 삭제
        }
    }
    for (int i=new_id.size()-1; i>0; i--)
        if (new_id[i-1] == '.' && new_id[i] == '.') new_id.erase(new_id.begin() + i);// 연속된 점이면 뒷점 삭제
    if (new_id[new_id.size()-1] == '.') new_id.erase(new_id.end()-1);// 시작이 점이면 삭제
    if (new_id[0] == '.') new_id.erase(new_id.begin());// 마지막이 점이면 삭제
    if (new_id == "") new_id += 'a';// 빈 문자열이면
    int size = new_id.size();
    if (size <= 2) while (new_id.size() != 3) new_id.push_back(new_id[size-1]);// 길이가 2보다 작으면 
    if (size >= 16) { // 길이가 16이상이면
        new_id = new_id.substr(0, 15);
        if (new_id[14] == '.') new_id.erase(new_id.end()-1); // 마지막이 점으로 끝나면
    }
    return new_id;
}