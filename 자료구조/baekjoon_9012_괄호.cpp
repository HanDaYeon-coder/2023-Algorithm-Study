#include <iostream>
#include <stack>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int T=0;    //테스트 케이스의 수
    string s;
    cin>>T;

    while(T--){
        cin>>s;

        stack<int> sta;
        string ans = "YES";
        for(int i=0; i<s.length(); i++){
            if(s[i]=='('){
                sta.push(1);
            }
            else{
                if(sta.empty()){
                    ans = "NO";
                    break;
                }
                else{
                    sta.pop();
                }
            }
        }
        if(!sta.empty()){
            ans = "NO";
        } 
        cout<<ans<<"\n";
    }
}
