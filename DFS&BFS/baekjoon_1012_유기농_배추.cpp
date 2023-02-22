#include <iostream>
#include <queue>
using namespace std;

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,1,-1};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int T = 0;  //테스트 케이스의 수
    cin>>T;

    while(T--){
        int M = 0, N =0, K=0;   //배추밭의 가로 길이, 세로 길이, 배추의 위치 개수
        int X = 0, Y =0;    //배추의 위치
        int answer = 0; //필요한 최소의 배추흰지렁이 마리 수

        cin>>M>>N>>K;

        int farm[M][N];
        for(int i=0; i<M; i++){
            for(int j=0; j<N; j++){
                farm[i][j] = 0;
            }
        }

        for(int i=0; i<K; i++){
            cin>>X>>Y;
            farm[X][Y] = 1;
        }

        for(int i=0; i<M; i++){
            for(int j=0; j<N; j++){
                if(farm[i][j] == 1){
                    queue<pair<int,int>> que;
                    que.push({i,j});
                    farm[i][j] = 0;

                    while(!que.empty()){
                        int hereX = que.front().first;
                        int hereY = que.front().second;
                        que.pop();

                        for(int k=0; k<4; k++){
                            int new_x = hereX+dx[k];
                            int new_y = hereY+dy[k];
                            if(new_x<0 or new_x >= M or new_y<0 or new_y >= N){
                                continue;
                            }
                            if(farm[new_x][new_y] == 1){
                                farm[new_x][new_y] = 0;
                                que.push({new_x, new_y});
                            }
                        }
                    }
                    answer++;
                }
            }
        }
        cout<<answer<<"\n";
    }
}
