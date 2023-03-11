#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string N;
    cin>>N;

    sort(N.begin(), N.end(), greater<char>());
    int sum = 0;
    for(int i=0; i<N.size(); i++){
        sum += (N[i]-'0');
    }

    if(sum%3 == 0 and N[N.size()-1] == '0'){
        cout<<N<<"\n";
    }
    else{
        cout<<-1<<"\n";
    }
    return 0;
}
