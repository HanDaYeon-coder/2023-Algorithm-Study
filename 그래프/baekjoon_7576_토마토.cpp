#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int m, n;  //상자의 가로 칸의 수, 상자의 세로 칸의 수
int tomato[1001][1001];   
int dx[4] = {0,1,-1,0};
int dy[4] = {1,0,0,-1};

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);

    cin >> m >> n;
    vector<pair<int,int>> wellTomato;   //익은 토마토 자리 칸
    int zeroTomato = 0; //익지 않은 토마토 개수
    for (int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++){
            cin >> tomato[j][i];    //1 : 익은 토마토, 0 : 익지 않은 토마토, -1 : 토마토가 들어있지 않은 칸
            if(tomato[j][i] == 1){
                wellTomato.push_back({j,i});
            }
            else if(tomato[j][i] == 0){
                zeroTomato++;
            }
        }
    }

    if(zeroTomato == 0){
        cout<<0<<"\n";  //저장될 때부터 모든 토마토가 익어있는 상태이면 0을 출력
        return 0;
    }
    
    queue<pair<pair<int,int>,int>> que; //위치 x, 위치 y, 깊이
    for(auto i : wellTomato){
        que.push({{i.first, i.second}, 0});
    }
    
    int ans = 0;
    int cnt = 0;    //익은 토마토 개수

    while (!que.empty())
    {
        int x = que.front().first.first;  int y = que.front().first.second; int depth = que.front().second;
        que.pop();
        ans = max(ans, depth);

        for(int i=0; i<4; i++){
            int X = x+dx[i];    int Y = y+dy[i];
            if(X>=m or X<0 or Y>=n or Y<0) continue;
            if(tomato[X][Y] == 1 or tomato[X][Y] == -1) continue;
            tomato[X][Y] = 1;
            cnt++;
            que.push({{X,Y},depth+1});
        }
    }
    
    if(cnt == zeroTomato)  cout<<ans<<"\n";
    else    cout<<-1<<"\n"; //토마토가 모두 익지는 못하는 상황이면 -1
}
