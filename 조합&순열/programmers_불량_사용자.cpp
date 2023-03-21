#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;

set<set<string>> answer;
map<string, bool> visited;
set<string> ans;
vector<vector<string>> valiable_banned_ids;

void permutation(int cnt){
    if(cnt == valiable_banned_ids.size()){
        answer.insert(ans);
        return;
    }
    for(int i=0; i<valiable_banned_ids[cnt].size(); i++){
        string x = valiable_banned_ids[cnt][i];
        if(!visited[x]){
            visited[x] = true;
            ans.insert(x);
            permutation(cnt+1);
            visited[x] = false;
            ans.erase(x);
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    for(int i=0; i<banned_id.size(); i++){
        vector<string> banned_ids;
        
        for(int j=0; j<user_id.size(); j++){
            if(banned_id[i].size() != user_id[j].size()){
                continue;
            }
            bool is_banned_id = true;
            for(int k=0; k<banned_id[i].size(); k++){
                if(banned_id[i][k] == '*'){
                    continue;
                }
                if(banned_id[i][k] != user_id[j][k]){
                    is_banned_id = false;
                    break;
                }
            }
            if(is_banned_id){
                banned_ids.push_back(user_id[j]);
            }
        }
        valiable_banned_ids.push_back(banned_ids);
    }
    
    permutation(0);
    
    return answer.size();
}
