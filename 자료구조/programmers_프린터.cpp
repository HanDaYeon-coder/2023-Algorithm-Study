#include <string>
#include <queue>
#include <vector>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0; 
    deque<pair<int,int>> dq;
    priority_queue<int, vector<int>> pq;

    for(int i=0; i<priorities.size(); i++){
        dq.push_back({priorities[i],i});
        pq.push({priorities[i]});
    }
    
    while(!pq.empty()){
        pair<int,int> J = dq.front();
        dq.pop_front();
        if( J.first == pq.top()){
            pq.pop();
            answer++;
            if(J.second == location){
                return answer;
            }
        }
        else{
            dq.push_back(J);
        }
    }
}
