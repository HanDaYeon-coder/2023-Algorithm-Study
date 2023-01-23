#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    
    for(int i=0; i<privacies.size(); i++){
        for(int j=0; j<terms.size(); j++){
            if(privacies[i][11] == terms[j][0]){
                int year = stoi(terms[j].substr(2)) / 12;
                int month = stoi(terms[j].substr(2)) % 12;
               
                int privacies_year = stoi(privacies[i].substr(0,4)) + year;
                int privacies_month = stoi(privacies[i].substr(5,2)) + month;
                int privacies_day = stoi(privacies[i].substr(8,2)) - 1;
                
                if(privacies_month > 12){
                    privacies_year += 1;
                    privacies_month -= 12;
                }
                if(privacies_day == 0){
                    privacies_day = 28;
                    privacies_month -= 1;
                    if(privacies_month == 0){
                        privacies_month = 12;
                        privacies_year -= 1;
                    }
                }
                
                string new_day = to_string(privacies_year) + '.';
                if(privacies_month <10){
                    new_day = new_day + '0' + to_string(privacies_month) + '.';
                }
                else{
                    new_day = new_day + to_string(privacies_month) + '.';
                }
                
                if(privacies_day <10){
                    new_day = new_day + '0' + to_string(privacies_day);
                }
                else{
                    new_day = new_day + to_string(privacies_day);
                }
               
                if(today > new_day){
                    answer.push_back(i+1);
                }
                cout<<new_day<<"\n";
                break;
            }
        }
    }
    
    
    return answer;
}
