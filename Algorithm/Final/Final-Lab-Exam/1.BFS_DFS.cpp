#include<bits/stdc++.h>
using namespace std;

int visitt[100];
vector<int> v[100];

void init(int n){
    for(int i=1;i<=n;i++){
        visitt[i]=0;
    }
}

void dfs(int node){
    visitt[node]=1;
    for(int i=0;i<v[node].size();i++){
        if(visitt[v[node][i]]==0){
            dfs(v[node][i]);
        }
    }
    cout << node << "\n";
}

void bfs(int node){
    queue<int> q;
    q.push(node);
    visitt[node]=1;

    while(!q.empty()){
        int now = q.front();
        q.pop();
        cout << now << "\n";

        for(int i=0;i<v[now].size();i++){
            if(visitt[v[now][i]]==0){
                q.push(v[now][i]);
                visitt[v[now][i]] = 1;
            }
        }
    }
}

int main(){
    int vert,e;
    cin >> vert >> e;

    init(vert);

    for(int i=0;i<e;i++){
        int a,b;
        cin >> a >> b;
        if(a==b){
            v[a].push_back(b);
        }else{
            v[a].push_back(b);
            v[b].push_back(a);
        }
    }

    // Print adjacency list
    for(int i=1;i<=vert;i++){
        cout << i << " : ";
        for(int j=0;j<v[i].size();j++){
            cout << v[i][j] << " ";
        }
        cout << "\n";
    }

    cout << "The output of DFS:\n";
    dfs(1);

    cout << "The output of BFS:\n";
    init(vert);
    bfs(1);

    return 0;
}




/*
Input :
6 7
1 2
1 3
2 4
2 5
3 6
4 5
5 6



Expected Output :

Adjacency List
1 : 2 3 
2 : 1 4 5 
3 : 1 6 
4 : 2 5 
5 : 2 4 6 
6 : 3 5 


DFS Traversal (post-order)
The output of DFS :
4
5
2
6
3
1




BFS Traversal
The output of BFS:
1
2
3
4
5
6

*/
