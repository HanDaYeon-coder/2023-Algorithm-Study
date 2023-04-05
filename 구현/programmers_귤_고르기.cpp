#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    vector<int> size_types;
    
    sort(tangerine.begin(), tangerine.end());
    
    int here = tangerine[0];
    int cnt = 0;
    for(int i=0; i<tangerine.size(); i++){
        if(here != tangerine[i]){
            size_types.push_back(cnt);
            cnt = 1;
            here = tangerine[i];
        }
        else{
            cnt++;
        }
    }
    size_types.push_back(cnt);
    
    sort(size_types.begin(), size_types.end(), greater<int>());
    
    for(int i = 0; k>0; i++){
        k -= size_types[i];
        answer++;
    }
    
    return answer;
}
