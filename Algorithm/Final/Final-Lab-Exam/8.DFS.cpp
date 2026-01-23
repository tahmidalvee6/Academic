#include<bits/stdc++.h>
using namespace std;

vector<int> v[100];
int visitt[100];

void dfs(int node){
    visitt[node] = 1;

    for(int i=0;i<v[node].size();i++){
        if(visitt[v[node][i]] == 0){
            dfs(v[node][i]);
        }
    }

    cout << node << "\n";   // post-order
}

int main(){
    int vert, e;
    cin >> vert >> e;

    for(int i=0;i<e;i++){
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    cout << "DFS Traversal\n";
    dfs(1);

    return 0;
}
