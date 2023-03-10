#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N = 0;
    int people[11];
    vector<int> lines;
    cin>>N;

    for(int i=1; i<=N; i++){
        cin>>people[i];
    }
    
    lines.push_back(N);
    for(int i=N-1; i>=1; i--){
        lines.insert(lines.begin()+people[i], i);
    }

    for(int ans : lines){
        cout<<ans<<" ";
    }
}
