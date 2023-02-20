#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF 300001

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int V = 0, E = 0;   //정점의 개수, 간선의 개수
    int K = 0;  //시작 정점
    int u = 0, v = 0, w = 0;

    cin>>V>>E>>K;

    vector<pair<int,int>>graph[V+1];    //연결된 정점의 번호, 가중치

    int cost[V+1];
    for(int i=0; i<=V; i++){
        cost[i] = INF;  //cost 무한대로 초기화
    }

    for(int i=0; i<E; i++){
        cin>>u>>v>>w;
        graph[u].push_back({v,w});
    }

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, K});
    cost[K] = 0;

    while(!pq.empty()){
        int here = pq.top().second;
        pq.pop();

        for(int i=0; i<graph[here].size(); i++){
            int idx = graph[here][i].first;
            int weight = graph[here][i].second;

            if(cost[idx] > cost[here]+weight){
                cost[idx] = cost[here]+weight;
                pq.push({cost[idx], idx});
            }
        }
    }

    for(int i=1; i<=V; i++){
        if(cost[i] == INF){
            cout<<"INF"<<"\n";
        }
        else{
            cout<<cost[i]<<"\n";
        }
    }    
}
