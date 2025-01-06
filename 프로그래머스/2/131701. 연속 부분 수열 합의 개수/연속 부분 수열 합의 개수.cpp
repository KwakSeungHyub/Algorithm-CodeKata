#include <string>
#include <vector>
#include <set>

using namespace std;

int arr[1001][1001];
set<int> s;

int solution(vector<int> elements) {
    int answer=0;
    
    for(int i=0; i<elements.size(); i++){
        arr[0][i]=elements[i];
        s.insert(elements[i]);
    }
    
    for(int i=1; i<elements.size(); i++){
        for(int j=0; j<elements.size(); j++){
            int y;
            if(j==0) y=elements.size()-1;
            else y=j-1;
            
            arr[i][j]=arr[i-1][y]+arr[0][j];
            s.insert(arr[i][j]);
        }
    }
    
    answer=s.size();
    
    return answer;
}