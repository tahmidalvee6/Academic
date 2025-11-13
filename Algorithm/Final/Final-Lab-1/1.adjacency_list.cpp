#include<bits/stdc++.h>
using namespace std;
int main() {
    freopen("in.txt", "r", stdin);

    int vert, e;
    cin>>vert>>e;

    vector<int>v[vert + 1];

    for(int i = 0; i < e; i++) {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    // for(int i = 0; i < e; i++) {
    //     int a,b;
    //     cin>>a>>b;
    //     if(a == b) {
    //         v[a].push_back(b);
    //     }
    //     else {
    //         v[a].push_back(b);
    //         v[b].push_back(a);
    //     }
    // }

    //vector output
    for(int i = 1; i <= vert; i++) {
        cout<<i<<" : ";
        for(int j = 0; j < v[i].size(); j++) {
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
}





