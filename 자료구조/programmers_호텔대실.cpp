#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int cmp(vector<string> a, vector<string> b){
    return a[0] < b[0]; //대실 시작 시각으로 정렬
}


int toTime(string time){    //string 시각 -> int 시각
    int minutes = stoi(time.substr(3,2));
    int hours = stoi(time.substr(0,2))*60;
    return hours+minutes;
}

int solution(vector<vector<string>> book_time) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> hotel;
    sort(book_time.begin(), book_time.end(), cmp);  
    hotel.push(toTime(book_time[0][1]));
    
    for(int i=1; i<book_time.size(); i++){
        int in_time = toTime(book_time[i][0]);  //대실 시작 시각
        int out_time = toTime((book_time[i][1]))+10; //대실 종료 시각
        
        if(hotel.top() > in_time){
            hotel.push(out_time);
        }
        else{
            hotel.pop();
            hotel.push(out_time);
        }
    }
    
    return hotel.size();
}
