#include <iostream>
using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);

   int K = 0;
   int Ka[46];  //A의 개수
   int Kb[46];  //B의 개수
   cin >> K;

    Ka[0] = 1;
    Kb[0] = 0;

    for(int i=1; i<=K; i++){
        Kb[i] = Ka[i-1] + Kb[i-1];
        Ka[i] = Kb[i-1];
    }
    
    cout<<Ka[K]<<" "<<Kb[K]<<"\n";
}
