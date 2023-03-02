#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    
    for(int i=0; i<maps.size(); i++){
        for(int j=0; j<maps[0].size(); j++){
            if(maps[i][j] != 'X'){
                int sum = maps[i][j] - '0';
                queue<pair<int,int>> que;
                que.push({i,j});
                maps[i][j] = 'X';
                
                while(!que.empty()){
                    int x = que.front().first;
                    int y = que.front().second;
                    que.pop();
                    
                    for(int k=0; k<4; k++){
                        int X = x + dx[k];
                        int Y = y + dy[k];
                        if(X < 0 or X >= maps.size() or Y < 0 or Y >= maps[0].size()){
                            continue;
                        }
                        if(maps[X][Y] != 'X'){
                            sum += maps[X][Y] - '0';
                            que.push({X,Y});
                            maps[X][Y] = 'X';
                        }
                    }
                }
                answer.push_back(sum);
            }
        }
    }
    
    if(answer.size() == 0){
        answer.push_back(-1);
    }
    else{
        sort(answer.begin(), answer.end());
    }
    
    return answer;
}
