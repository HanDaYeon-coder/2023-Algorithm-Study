#include <iostream>
using namespace std;

int N=0;
int M=0;
int arr[9] = {0,};

void combination(int cnt, int next){
    if(cnt == M){
        for(int i = 0; i<M; i++){
            cout<<arr[i]<<" ";
        }
        cout<<"\n";
        return;
    }
    
    for(int i=next; i<=N; i++){
        arr[cnt] = i;
        combination(cnt+1, i+1);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>N>>M;
    combination(0,1);
}
