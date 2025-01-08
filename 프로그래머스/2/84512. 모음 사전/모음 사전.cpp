#include <string>
#include <vector>

using namespace std;

string AEIOU = "AEIOU";
int count = 0;
int answer = -1;

void dfs(string start, string word)
{
    if(count == answer)
        return;
    
    for(int i = 0; i < 5; i++)
    {
        start += AEIOU[i];
        count++;
        if(start == word)
        {
            answer = count;
            return;
        }
        if(start.length() < 5)
            dfs(start, word);
        start.pop_back();
    }
}

int solution(string word) {
    
    dfs("", word);
    
    return answer;
}