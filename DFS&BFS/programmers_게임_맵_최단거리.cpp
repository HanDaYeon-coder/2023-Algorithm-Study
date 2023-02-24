#include <vector>
#include <queue>
using namespace std;

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,1,-1};

int solution(vector<vector<int>> maps)
{
    int m = maps.size();
    int n = maps[0].size();
    
    queue<pair<pair<int,int>,int>> que; //위치, 깊이
    que.push({{0,0},1});
    maps[0][0] = 0;
                
    while(!que.empty()){
        int x = que.front().first.first;
        int y = que.front().first.second;
        int depth = que.front().second;
        que.pop();
                    
        if(x == m-1 and y == n-1){
            return depth;
        }
                    
        for(int k=0; k<4; k++){
            int X = x+dx[k]; int Y = y+dy[k];
            if(X < 0 or X > m-1 or Y < 0 or Y > n-1){
                continue;
            }
            if(maps[X][Y] == 1){
                maps[X][Y] = 0;
                que.push({{X,Y},depth+1});
            }
        }
    }
    return -1;
}
