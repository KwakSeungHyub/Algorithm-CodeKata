#include <string>
#include <vector>
#include <set>
using namespace std;

// 조합 경우의 수
/*
     1(0001) - 학번
     2(0010) - 이름
     3(0011) - 이름, 학번
     4(0100) - 전공
     5(0101) - 학번, 전공
     6(0110) - 이름, 전공
     7(0111) - 학번, 이름, 전공
     8(1000) - 학년
     9(1001) - 학번, 학년
     10(1010) - 이름, 학년
     11(1011) - 학번, 이름, 학년
     12(1100) - 이름, 학번
     13(1101) - 학번, 전공, 학년
     14(1110) - 이름, 전공, 학년
     15(1111) - 학번, 이름, 전공, 학년
*/

bool possi(vector<int> vec, int now){
    for(auto v : vec)// &연산을 한결과가 0이 아니라는 뜻은 아무튼 뭔가는 포함되어있다는 의미
        if((v & now) == v)// 그 결과가 v와 같다는 것은 최소단위가 동일한지 체크하는 부분
            return false;
    return true;
}

int solution(vector<vector<string>> relation) {
    int rowSize = relation.size(); 
    int colSize = relation[0].size();
    int posible_cnt = 1 << colSize; //나올 수 있는 속성 조합
    vector<int> ans;

    for (int i = 1; i < posible_cnt; i++) {
        set<string> s;
        for (int j = 0; j < rowSize; j++) {
            string now = "";

            for (int k = 0; k < colSize; k++) {
                if (i & (1<<k)) now += relation[j][k];
            }
            s.insert(now);
        }
        if (s.size() == rowSize && possi(ans,i)) ans.push_back(i);
        // 사이즈가 같지않다면 중복된 값이 존재한다는 의미
        // Posii에서는 최소단위인지 측정
    }

    return ans.size();
}