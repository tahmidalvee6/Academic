#include<bits/stdc++.h>
using namespace std;

vector<int> v[100];
int visitt[100];

void bfs(int node){
    queue<int> q;
    q.push(node);
    visitt[node] = 1;

    while(!q.empty()){
        int now = q.front();
        q.pop();
        cout << now << "\n";

        for(int i=0;i<v[now].size();i++){
            if(visitt[v[now][i]] == 0){
                q.push(v[now][i]);
                visitt[v[now][i]] = 1;
            }
        }
    }
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

    cout << "BFS Traversal\n";
    bfs(1);

    return 0;
}
