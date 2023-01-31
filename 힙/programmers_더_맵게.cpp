#include <string>
#include <queue>
#include <vector>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for(int i : scoville){
        pq.push(i);
    }
    
    while(pq.top() < K and pq.size() != 1){
        int first = pq.top();   pq.pop();
        int second = pq.top();  pq.pop();
        int new_scoville = first + second*2;
        pq.push(new_scoville);
        answer++;
    }
    
    if(pq.size()== 1){
        if(pq.top()<K){
            answer = -1;
        }
    }
    
    return answer;
}
