#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int parents[101];   //부모 노드

int cmp(vector<int> a, vector<int> b){
    return a[2] < b[2];
}

int find(int x){  //find 연산-> 어떤 집합에 속해있는지 찾는다.
    if(parents[x] == x) return x;
    return parents[x] = find(parents[x]);
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    
    //자기 자신을 부모로 지정
    for(int i=0; i<n; i++){
        parents[i] = i;
    }
    
    sort(costs.begin(), costs.end(), cmp);
    
    for(int i=0; i<costs.size(); i++){
        //union 과정 -> 같은 집합에 있지 않은 경우에만, 두 집합을 병합한다.
        int x = find(costs[i][0]);
        int y = find(costs[i][1]);
        int cost = costs[i][2];
        
        if(x != y){ //사이클을 형성하지 않는다면
            parents[y] = x;
            answer+=cost;
        }
    }
    
    return answer;
    
}
