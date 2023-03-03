#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

int combi[11] = {0, };
int max_course[11] = {0,};  //코스 길이별 최대 주문 횟수
map<string, int> course_nums;    //해당 메뉴 조합의 주문 횟수
set<pair<int,string>> courses;    //코스 요리 이름 길이, 코스 메뉴 이름들

// 각 회원별로 나올 수 있는 메뉴 조합 구하기
void combination(int cnt, int next, int n, string order){
    if(cnt == n){
        string course;
        for(int i=0; i<n; i++){
            course += order[combi[i]];
        }
        sort(course.begin(), course.end());
        course_nums[course] += 1;
        courses.insert({n,course});
        max_course[n] = max(max_course[n], course_nums[course]);
        return;
    }
    
    for(int i=next; i<order.size(); i++){
        combi[cnt] = i;
        combination(cnt+1, i+1, n, order);
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    
    for(int i=0; i<orders.size(); i++){
        for(int j=0; j<course.size(); j++){
            if(course[j] <= orders[i].size()){
                combination(0,0,course[j],orders[i]);
            }
        }
    }
    
    for(int i=0; i<course.size(); i++){
        if(max_course[course[i]] < 2){
            continue;
        }
        for(auto j : courses){
            if(j.first == course[i]){
                if(course_nums[j.second] == max_course[course[i]]){
                    answer.push_back(j.second);
                }
            }
        }
    }
    
    sort(answer.begin(), answer.end());
    
    return answer;
}
