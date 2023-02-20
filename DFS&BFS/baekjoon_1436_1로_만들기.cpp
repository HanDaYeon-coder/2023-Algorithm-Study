#include <iostream>
#include <queue>
using namespace std;

int check[1000001] = {0,};
int parent[1000001] = {0,};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N = 0; 
    cin>>N;

    queue<int> que;
    check[1] = 1;
    que.push(1);

    while(!que.empty()){
        int here = que.front();
        que.pop();
        int first = here*3; int second = here*2; int third = here+1;

        if(here == N){
            cout<<parent[here]<<"\n";
        }

        if(first <= N and check[first] == 0){
            parent[first] = parent[here] +1;
            check[first] = 1;
            que.push(first);
        }
        if(second <= N and check[second] == 0){
            parent[second] = parent[here] + 1;
            check[second] = 1;
            que.push(second);
        }
        if(third <= N and check[third] == 0){
            parent[third] = parent[here] + 1;
            check[third] = 1;
            que.push(third);
        }
    }
}
