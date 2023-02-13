#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);

   int N = 0;
   int red = 0, green = 0, blue = 0;
   int house[3] = {0,}; //빨강, 녹색, 파랑
   cin>>N;

   for(int i=1; i<=N; i++){
        cin >> red >> green >> blue;
        int house1 = house[0]; 
        int house2 = house[1]; 
        int house3 = house[2];
        
        house[0] = red + min(house2, house3);
        house[1] = green + min(house1, house3);
        house[2] = blue + min(house1, house2);
    }
    cout<<min(house[0], min(house[1], house[2]))<<"\n";
}
