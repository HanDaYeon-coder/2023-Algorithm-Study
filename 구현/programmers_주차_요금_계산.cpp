#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <set>
using namespace std;

int park_fees(vector<int> fees, int park_times){
    if(fees[0] > park_times){
            return fees[1];
    }
    else if(((park_times-fees[0])%fees[2]) != 0){
        return fees[1] + ((park_times-fees[0])/fees[2]+1) * fees[3];
    }
    else{
        return fees[1] + (park_times-fees[0])/fees[2] * fees[3];
    }
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    set<string> car_names;
    map<string, vector<int>> cars;
    
    for(int i=0; i<records.size(); i++){
        stringstream ss(records[i]);
        string time, car, state;
        ss >> time >> car >> state;
        int hour = (time[0]-'0')* 10 + (time[1] - '0');
        int minute = (time[3]-'0')* 10 + (time[4] - '0');
        cars[car].push_back(hour*60 + minute);
        car_names.insert(car);
    }
    
    for(auto idx : car_names){
        int car_nums = cars[idx].size();
        int park_times = 0;
        if(car_nums % 2 == 1){
            park_times = (1439 - cars[idx][car_nums-1]);
            car_nums -= 1;
        }
        for(int i=0; i< car_nums; i+=2){
            park_times += (cars[idx][i+1]-cars[idx][i]);
        }
        answer.push_back(park_fees(fees, park_times));
    }
    return answer;
}
