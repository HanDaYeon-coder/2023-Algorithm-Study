#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

char map[51][51];

int chess(char start, char next, int i, int j){
    int cnt = 0;
    for(int k=0; k<8; k++){
        for(int l=0; l<8; l++){
            if(l%2==0){
                if(map[i+k][j+l] != start){
                    cnt++;
                }
            }
            else{
                if(map[i+k][j+l] != next){
                    cnt++;
                }
            }
        }
        swap(start, next);
    }
    return cnt;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N = 0;
    int M = 0;
    
    int answer = 64;
    cin>>N>>M;

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin>>map[i][j];
        }
    }

    for(int i=0; i<=N-8; i++){
        for(int j=0; j<=M-8; j++){
            answer = min(answer, chess('W','B', i, j));
            answer = min(answer, chess('B','W', i, j));
        }
    }
    cout<<answer<<"\n";
}
