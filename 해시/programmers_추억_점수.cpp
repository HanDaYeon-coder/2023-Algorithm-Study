#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    map<string, int> points;
    
    for(int i=0; i<name.size(); i++){
        points[name[i]] = yearning[i];
    }
    
    for(int i=0; i<photo.size(); i++){
        int sum_points = 0;
        for(int j=0; j<photo[i].size(); j++){
            sum_points += points[photo[i][j]];
        }
        answer.push_back(sum_points);
    }
    
    return answer;
}
