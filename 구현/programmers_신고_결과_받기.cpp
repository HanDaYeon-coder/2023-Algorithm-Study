#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <set>
using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    map<string, set<string>> alert_users;
    map<string, int> user_messages;
    
    for(int i=0; i<report.size(); i++){
        stringstream ss(report[i]);
        string user, alert;
        ss >> user >> alert;
        alert_users[alert].insert(user);
    }
    
    for(int i=0; i<id_list.size(); i++){
        if(alert_users[id_list[i]].size() >= k){
            for(auto idx : alert_users[id_list[i]]){
                user_messages[idx] += 1;
            }
        }
    }
    
    for(int i=0; i<id_list.size(); i++){
        answer.push_back(user_messages[id_list[i]]);
    }
    
    return answer;
}
