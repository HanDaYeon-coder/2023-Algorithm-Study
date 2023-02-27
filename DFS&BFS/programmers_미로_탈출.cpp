#include <string>
#include <vector>
#include <queue>
using namespace std;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int bfs(vector<string> maps2, int i, int j, char dest){
    queue<pair<pair<int,int>,int>> que;
    que.push({{i,j},0});
    maps2[i][j] = 'X';
                
    while(!que.empty()){
        pair<int,int> here = que.front().first;
        int time = que.front().second;
        que.pop();
        
        for(int k=0; k<4; k++){
            int X = here.first + dx[k]; 
            int Y = here.second + dy[k];
            if(X < 0 or X >= maps2.size() or Y < 0 or Y >= maps2[0].size()){
                continue;
            }
            if(maps2[X][Y] != 'X'){
                if(maps2[X][Y] == dest){
                    return time+1;
                }
                que.push({{X,Y}, time+1});
                maps2[X][Y] = 'X';
            }
        }
    }
    return -1;
}

int solution(vector<string> maps) {
    pair<int,int> start, levor;
    
    for(int i=0; i<maps.size(); i++){   
        for(int j=0; j<maps[i].size(); j++){
            if(maps[i][j] == 'S'){
                start = {i, j};
            }
            else if(maps[i][j] == 'L'){
                levor = {i, j};
            }
        }
    }
    
    int sToLTimes = bfs(maps, start.first, start.second, 'L'); //시작 -> 레버 이동 시간
    if(sToLTimes == -1) return -1;
    
    int lToETimes = bfs(maps, levor.first, levor.second, 'E'); //레버 -> 출구 이동 시간
    if(lToETimes == -1) return -1;
    
    return sToLTimes + lToETimes;
}
