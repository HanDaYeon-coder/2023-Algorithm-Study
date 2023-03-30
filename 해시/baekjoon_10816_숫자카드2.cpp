#include <iostream>
#include <map>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    map<int, int> cards;

    int N = 0;
    int M = 0;
    int x = 0;

    cin>>N;

    for(int i=0; i<N; i++){
        cin>>x;
        cards[x] += 1;
    }

    cin>>M;
    for(int i=0; i<M; i++){
        cin>>x;
        cout<<cards[x]<<" ";
    }
    
    cout<<"\n";
    return 0;
}
