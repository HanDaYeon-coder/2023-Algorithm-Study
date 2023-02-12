#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);

   int N = 0;
   cin>>N;
  
   int cards[N+1];
   int dp[N+1];

   for(int i=1; i<=N; i++){
        cin>>cards[i];
        dp[i] = 0;
   }

    dp[0] = 0;
    dp[1] = cards[1];

    for(int i=2; i<=N; i++){
        for(int j=1; j<=i; j++){
            dp[i] = max(dp[i], cards[j]+dp[i-j]);
        }
    }
    cout<<dp[N]<<"\n";
}
