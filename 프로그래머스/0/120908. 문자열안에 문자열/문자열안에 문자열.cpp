#include <string>
#include <vector>

using namespace std;

int solution(string str1, string str2) {
    int answer = 2;
    for(int i = 0; i < str1.size()-2; i++)
    {
        string a = "";
        for(int j = 0; j < str2.size(); j++)
        {
            a += str1[i+j];
        }
        if(a == str2)
        {
            answer = 1;
            break;
        }
    }
    return answer;
}