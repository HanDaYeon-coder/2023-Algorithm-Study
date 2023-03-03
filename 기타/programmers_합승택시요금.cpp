#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define INF 1e9

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    long long answer = INF;
    int m[201][201];
    
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            m[i][j] = INF;
        }
        m[i][i] = 0;
    }
    
    for(int i=0; i<fares.size(); i++){
        int x = fares[i][0];
        int y = fares[i][1];
        m[x][y] = m[y][x] = fares[i][2];
    }
    
    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                m[i][j] = min(m[i][j], m[i][k]+m[k][j]);
            }
        }
    }
    
    for(int i=1; i<=n; i++){
       answer = min(answer, (long long) (m[s][i]+m[i][a]+m[i][b]));
    }
    
    return answer;
}
