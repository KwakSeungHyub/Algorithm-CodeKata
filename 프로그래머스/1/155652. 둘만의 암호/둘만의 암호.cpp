#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool is_skip(char c, string skip) // 스킵문자인지
{
    for(int i=0;i<skip.size();i++)
        if (c == skip[i]) return true;
    return false;
}

string solution(string s, string skip, int index)
{
    string answer = "";
    for(int i=0;i<s.size();i++)
    {
        char c = s[i];
        for(int j=0;j<index;)
        {
            c += 1;
            if (c == 'z' + 1) c = 'a'; // 'z'를 넘어가면 'a'로 바꿔준다.
            if(!is_skip(c, skip)) // skip에 포함되지 않는 문자이면 카운트
                j++;
        }
        answer.push_back(c);
    }
    return answer;
}