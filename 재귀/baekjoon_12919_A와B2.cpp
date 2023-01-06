#include <iostream>
#include <algorithm>
using namespace std;

string S;
string T;

void AB(int k){
    if(k==S.length()){
        if(S == T){
            cout<<1<<"\n";
            exit(0);
        }
        return;
    }

    if(*--T.end() == 'A'){
        T.pop_back();
        AB(k-1);
        T.push_back('A');
    }
    if(*T.begin() == 'B'){
        reverse(T.begin(), T.end());
        T.pop_back();
        AB(k-1);
        T.push_back('B');
        reverse(T.begin(), T.end());
    }
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    cin>>S;
    cin>>T;

    AB(T.length());
    cout<<0<<"\n";
}
