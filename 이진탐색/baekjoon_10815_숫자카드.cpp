#include <iostream>
#include <set>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int N = 0, M=0;
    int a=0, b=0;
    set<int> s1;

    cin>>N;
    while(N--){
        cin>>a;
        s1.insert(a);
    }

    cin>>M;
    while(M--){
        cin>>b;
        cout<< s1.count(b)<<" ";
    }
}
