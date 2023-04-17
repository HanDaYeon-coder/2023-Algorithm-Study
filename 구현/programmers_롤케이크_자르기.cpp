#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    map<int,int> older;
    set<int> older_set;
    map<int,int> younger;
    set<int> younger_set;
    
    for(int i=0; i<topping.size(); i++){
        younger[topping[i]] += 1;
        younger_set.insert(topping[i]);
    }
    
    for(int i=0; i<topping.size(); i++){
        older[topping[i]] += 1;
        older_set.insert(topping[i]);
        
        younger[topping[i]] -= 1;
        if(younger[topping[i]] == 0){
            younger_set.erase(topping[i]);
        }
        
        if(older_set.size() == younger_set.size()){
            answer++;
        }
    }
    
    return answer;
}
