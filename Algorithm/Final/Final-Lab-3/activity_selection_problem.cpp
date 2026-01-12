//Activity Selection Problem
#include<bits/stdc++.h>
using namespace std;
class node{
public:
    int activity_number;
    int start_time;
    int end_time;
};

bool compare(node &A, node &B){
    return A.end_time < B.end_time;
}

bool compare2(pair<int,pair<int,int>> &A, pair<int,pair<int,int>> &B){
    return A.second.second < B.second.second;
}

vector< pair<int,pair<int,int> > > v1;
vector<node> v2;

int main(){

    int n;
    cin >> n;
    node temp;
    int a, b, c;

    for(int i = 0; i < n; i++){
        cin >> a >> b >> c;
        temp.activity_number = a;
        temp.start_time = b;
        temp.end_time = c;
        v2.push_back(temp);
        v1.push_back({a, {b, c}});
    }

    sort(v2.begin(), v2.end(), compare);
    sort(v1.begin(), v1.end(), compare2);

    for(int i = 0; i < n; i++){
        cout << "(" 
             << v2[i].activity_number << ", " 
             << v2[i].start_time << ", " 
             << v2[i].end_time << ")" << endl;
    }

    vector<int> selected;
    selected.push_back(v2[0].activity_number);
    int last_end = v2[0].end_time;

    for(int i = 1; i < n; i++){
        if(v2[i].start_time >= last_end){
            selected.push_back(v2[i].activity_number);
            last_end = v2[i].end_time;
        }
    }
    
    cout<<endl;

    cout << "Selected Activities: ";
    for(int x : selected){
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
