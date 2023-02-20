#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N = 0;  //지도의 크기 
    cin>>N;

    int graph[26][26];   //지도
    string x;
    vector<int> answer;

    for(int i=0; i<N; i++){
        cin>>x;
        for(int j=0; j<N; j++){
            if(x[j] == '0'){
                graph[i][j] = 0; //집 정보 (1 : 집이 있는 곳, 0 : 집이 없는 곳)
            }
            else{
                graph[i][j] = 1;
            }
        }
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(graph[i][j] == 1){
                int ans = 0;
                queue<pair<int,int>> que;
                que.push({i,j});
                graph[i][j] = 0;

                while(!que.empty()){
                    int a = que.front().first;
                    int b = que.front().second;
                    que.pop();
                    ans++;

                    for(int k=0; k<4; k++){
                        int X = a+dx[k];    int Y = b+dy[k];
                        if(X >= N or X < 0 or Y >= N or Y < 0){
                            continue;   
                        }
                        if(graph[X][Y] == 1){
                            que.push({X,Y});
                            graph[X][Y] = 0;
                        }
                    }
                }

                answer.push_back(ans);

            }
        }
    }

    sort(answer.begin(), answer.end());
    
    cout<<answer.size()<<"\n";

    for(int idx : answer){
        cout<<idx<<"\n";
    }
}
