#include <iostream>
#include <algorithm>
#include <vector>https://github.com/HanDaYeon-coder/2023-Algorithm-Study/blob/main/baekjoon_11000_강의실배정.cpp
#include <queue>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int N = 0;
    int S =0, T = 0;    //시작시간, 종료시간
    vector<pair<int,int>> timeTable;
    cin>>N;
    vector<long long> v;

    while(N--){
        cin>>S>>T;
        timeTable.push_back({S,T});
    }

    //시작시간 순서대로 정렬한다.
    sort(timeTable.begin(), timeTable.end());

    priority_queue<int, vector<int>, greater<int>> pq;
    
    pq.push(timeTable[0].second);

    for(int i=1; i<timeTable.size(); i++){
        pq.push(timeTable[i].second);
        if(pq.top()<=timeTable[i].first){
            pq.pop();
        }
    }
    cout<<pq.size()<<"\n";
}
