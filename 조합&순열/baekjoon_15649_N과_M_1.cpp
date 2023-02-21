#include <iostream>
#include <vector>
using namespace std;

int N=0;
int M=0;
vector<int> v;
bool check[9] = {false,};   //중복 여부 체크

void permutation(int cnt){
    if(cnt == M){
        for(int idx : v){
            cout<<idx<<" ";
        }
        cout<<"\n";
        return;
    }
    
    for(int i=1; i<=N; i++){
        if(!check[i]){
            v.push_back(i);
            check[i] = true;
            permutation(cnt+1);
            check[i]= false;
            v.pop_back();
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>N>>M;
    permutation(0);
}
