#include <string>
        
        
          
          #include <vector>
        
        
          
          using namespace std;
        
        
          
          

        
        
          
          const int MAX = 120 + 12;
        
        
          
          

        
        
          
          // dp[a][b] : A의 누적 흔적이 a, B의 누적 흔적이 b인 상태 가능 여부
        
        
          
          bool dp[MAX][MAX];
        
        
          
          

        
        
          
          int solution(vector<vector<int>> info, int n, int m) {
        
        
          
              int itemCnt = info.size();
        
        
          
              dp[0][0] = true;
        
        
          
              
        
        
          
              for (int i = 0; i < itemCnt; i++) 
        
        
          
              {
        
        
          
                  bool nextDp[MAX][MAX] = {false, };
        
        
          
                  int traceA = info[i][0];
        
        
          
                  int traceB = info[i][1];
        
        
          
                  
        
        
          
                  for (int a = 0; a < n; a++) 
        
        
          
                  {
        
        
          
                      for (int b = 0; b < m; b++) 
        
        
          
                      {
        
        
          
                          if (!dp[a][b]) 
        
        
          
                          {
        
        
          
                              continue;
        
        
          
                          }
        
        
          
                          
        
        
          
                          if (a + traceA < n) 
        
        
          
                          {
        
        
          
                              nextDp[a + traceA][b] = true;
        
        
          
                          }
        
        
          
                          
        
        
          
                          if (b + traceB < m) 
        
        
          
                          {
        
        
          
                              nextDp[a][b + traceB] = true;
        
        
          
                          }
        
        
          
                      }
        
        
          
                  }
        
        
          
                  
        
        
          
                  for (int a = 0; a < n; a++) 
        
        
          
                  {
        
        
          
                      for (int b = 0; b < m; b++) 
        
        
          
                      {
        
        
          
                          dp[a][b] = nextDp[a][b];
        
        
          
                      }
        
        
          
                  }
        
        
          
              }
        
        
          
              
        
        
          
              for (int a = 0; a < n; a++) 
        
        
          
              {
        
        
          
                  for (int b = 0; b < m; b++) 
        
        
          
                  {
        
        
          
                      if (dp[a][b])
        
        
          
                      {
        
        
          
                          return a;
        
        
          
                      }
        
        
          
                  }
        
        
          
              }
        
        
          
          

        
        
          
              return -1;
        
        
          
          }
