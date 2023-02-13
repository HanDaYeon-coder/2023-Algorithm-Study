#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

int solution(int x, int y, int n) {
    int answer = -1;
    queue<pair<int,int>> que;
    unordered_map<int, bool> check;    //방문 여부
    que.push({x,0});
    
    while(!que.empty()){
        int here = que.front().first;
        int depth = que.front().second;
        check[here] = true;
        que.pop();

        if(here == y){
            answer = depth;
            break;
        }
        if(here > y){
            continue;
        }
        
        if(!check[here + n]){
            que.push({here + n, depth+1});
        }
        if(!check[here * 2]){
            que.push({here * 2, depth+1});
        }
        if(!check[here * 3]){
            que.push({here * 3, depth+1});
        }
    }
    return answer;
}
