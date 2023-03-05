#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<string>names;

bool compare(vector<int> a, vector<int> b){
    if(a[0] == b[0]){
        if(a[1] == b[1]){
            if(a[2] == b[2]){
                return names[a[3]] < names[b[3]];
            }
            return a[2] > b[2];
        }
        return a[1] < b[1];
    } 
    return a[0] > b[0];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N = 0;
    vector<vector<int>>students;
    string name; 
    int korean = 0, english = 0, math = 0;
    cin>>N;

    for(int i=0; i<N; i++){
        vector<int> student;
        cin>>name>>korean>>english>>math;
        student.push_back(korean);
        student.push_back(english);
        student.push_back(math);
        student.push_back(i);
        students.push_back(student);
        names.push_back(name);
    }
    sort(students.begin(), students.end(), compare);

    for(int i=0; i<N; i++){
        cout<<names[students[i][3]]<<"\n";
    }
}
