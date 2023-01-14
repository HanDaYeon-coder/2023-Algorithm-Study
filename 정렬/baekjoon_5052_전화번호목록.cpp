#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    int t = 0;  //테스트 케이스 수
    int n = 0;  //전화번호 수
    cin>>t;

    while(t--){
        cin>>n;
        string phoneNumber;
        vector<string> number;
        for(int i=0; i<n; i++){
            cin>>phoneNumber;
            number.push_back(phoneNumber);
        }

        sort(number.begin(), number.end());

        string ans = "YES";

        for(int i = 0; i < n; i++){
            for(int j=i+1; j<n; j++){
                if(number[i].size() > number[j].size()) break;
                if(number[i][0] != number[j][0])    break;
                if(number[i] == number[j].substr(0, number[i].size())){
                    ans = "NO";
                    break;
                }
            }
            if(ans == "NO") break;
        }
        cout<<ans<<"\n";
    }
}
