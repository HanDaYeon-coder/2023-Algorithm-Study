#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> graph[500001];  
unordered_map<int, int> depth; //해당 노드의 번호, 깊이
unordered_map<int, bool> check;  //방문 여부
int leapDepthSum = 0;

void dfs(int here){
    check[here] = true;
    bool leapCheck = true;  //leap인지 확인
    for(int i=0; i<graph[here].size(); i++){
        if(!depth[graph[here][i]]){
            leapCheck = false;
            depth[graph[here][i]] = depth[here]+1;
            dfs(graph[here][i]);
        }
    }
    if(leapCheck){
        leapDepthSum += depth[here]; 
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N = 0;  //트리의 정점 개수
    int a = 0, b = 0;   //트리의 간선 정보
    
    cin>>N;

    for(int i=0; i<N-1; i++){
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    depth[1] = 0;
    dfs(1);

    if(leapDepthSum%2 == 0){
        cout<<"No"<<"\n";
    }
    else{
        cout<<"Yes"<<"\n";
    }
}
