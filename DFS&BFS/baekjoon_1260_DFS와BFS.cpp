#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string.h>
using namespace std;

vector<int> graph[10001];
bool check[10001] = {false, };

void dfs(int x){
    cout<<x<<" ";
    check[x] = true;
    for(int i=0; i<graph[x].size(); i++){
        if(!check[graph[x][i]]){
            dfs(graph[x][i]);
        }
    }
}

void bfs(int x){
    queue<int> que;
    que.push(x);
    check[x] = true;

    while(!que.empty()){
        int here = que.front();
        cout<<here<<" ";
        que.pop();
        
        for(int i=0; i<graph[here].size(); i++){
            if(!check[graph[here][i]]){
                que.push(graph[here][i]);
                check[graph[here][i]] = true;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int N=0, M = 0, V = 0;  //정점의 개수, 간선의 개수, 탐색 시작 정점 번호
    int a = 0, b =0;    //정점 번호
    cin>>N>>M>>V;

    while(M--){
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for(int i=1; i<=N; i++){
        sort(graph[i].begin(), graph[i].end());
    }

    dfs(V);
    memset(check, false, 10001);
    cout<<"\n";
    bfs(V);
}
