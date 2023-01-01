#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int T=0;    //테스트 케이스의 수
    string p;   //수행할 함수
    int n=0;    //배열의 길이
    string arr; //배열
    deque<int> ac;

    cin>>T;

    while(T--){
       cin>>p>>n>>arr;
       
       bool error = 0;
       string s = "";

       for(int i=1; i<arr.length()-1; i++){
            if(arr[i]==','){
                ac.push_back(stoi(s));
                s="";
            }
            else s += arr[i];
       }
       if(s!=""){
            ac.push_back(stoi(s));
       }

        bool direction = 0;  //0 : 정방향(앞방향 = 왼쪽-> 오른쪽), 1:반대방향 (뒤쪽 방향 = 오른쪽 -> 왼쪽)

        for(int i=0; i<p.length(); i++){
            if(p[i]=='R'){ 
                if(direction == 0) direction = 1;
                else direction = 0;
            }
            else{   //p[i] == 'D'인 경우
                if(ac.empty()){
                    cout<<"error"<<"\n";
                    error = 1;
                    break;
                }
                else{
                    if(direction == 0)  ac.pop_front();
                    else ac.pop_back();
                }
            }
        }

        if(direction == 0 and !ac.empty()){
            cout<<"[";
            while(ac.size()>1){
                cout<<ac.front()<<",";
                ac.pop_front();
            }
            cout<<ac.front()<<"]\n";
            ac.pop_front();
        }
        else if(direction == 1 and !ac.empty()){
            cout<<"[";
            while(ac.size()>1){
                cout<<*--ac.end()<<",";
                ac.pop_back();
            }
            cout<<ac.front()<<"]\n";
            ac.pop_back();
        }
        else if (ac.empty() and error != 1){
            cout<<"[]"<<"\n";
        }
    }
}
