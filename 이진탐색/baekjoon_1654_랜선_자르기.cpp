#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> lines;

int cut_lines(int length){
    int cnt = 0;
    for(int i=0; i<lines.size(); i++){
        cnt += lines[i]/length;
    }
    return cnt;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int K = 0, N = 0;
    int line_length = 0;
    int max_line = 0;

    cin>>K>>N;
    
    for(int i=0; i<K; i++){
        cin>>line_length;
        lines.push_back(line_length);
        max_line = max(max_line, line_length);
    }

    long long low = 1;
    long long high = max_line;
    long long ans = 0;

    while(low <= high){
        long long mid = (low + high) / 2;
        int cnt_lines = cut_lines(mid);

        if(cnt_lines < N){
            high = mid - 1;
        }
        else{
            low = mid + 1;
            ans = mid;
        }
    }

    cout<<ans<<"\n";

    return 0;
}
