#include <string>
#include <vector>

using namespace std;

string beans(int generation, int idx){
    if(generation == 1) return "Rr";
    
    string parent_bean = beans(generation-1, (idx/4));
    
    if(parent_bean == "RR") return "RR";
    else if (parent_bean == "rr") return "rr";
    else {
        int bean_sort = idx%4;
        if(bean_sort == 0) return "RR";
        if(bean_sort == 1 or bean_sort == 2) return "Rr";
        return "rr";
    }
}

vector<string> solution(vector<vector<int>> queries) {
    vector<string> answer;
    
    for(int i=0; i<queries.size(); i++){
        answer.push_back(beans(queries[i][0], queries[i][1]-1));
    }
    
    return answer;
}
