#include <iostream>
#include <queue>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N = 0;
    cin>>N;
    queue<int> que;

    for(int i=1; i<=N; i++){
        que.push(i);
    }

    while(que.size() != 1){
        que.pop();
        int first = que.front();
        que.pop();
        que.push(first);
    }
    
    cout<<que.front()<<"\n";
    return 0;
}
