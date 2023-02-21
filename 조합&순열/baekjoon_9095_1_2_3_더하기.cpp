#include <iostream>
using namespace std;

int N=0;
int answer = 0;
int arr[12] = {0,};

void permutation(int cnt, int M){
    if(cnt == M){
        int sum = 0;
        for(int i = 0; i<M; i++){
            sum += arr[i];
        }
        if(sum == N){
            answer++;
        }
        return;
    }
    
    for(int i=1; i<=3; i++){
        arr[cnt] = i;
        permutation(cnt+1, M);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int T;
    cin>>T;

    while(T--){
        cin>>N;
        for(int i=1; i<=N; i++){
            permutation(0, i);
        }
        cout<<answer<<'\n';
        answer = 0;
    }
}
