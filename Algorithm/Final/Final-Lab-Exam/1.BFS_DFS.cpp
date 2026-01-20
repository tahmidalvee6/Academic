#include<bits/stdc++.h>
using namespace std;

int visitt[100];
vector<int> v[100];
int adjMatrix[100][100]; // adjacency matrix

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

    // initialize adjacency matrix
    for(int i=1;i<=vert;i++){
        for(int j=1;j<=vert;j++){
            adjMatrix[i][j] = 0;
        }
    }

    for(int i=0;i<e;i++){
        int a,b;
        cin >> a >> b;
        if(a==b){
            v[a].push_back(b);
            adjMatrix[a][b] = 1;
        } else {
            v[a].push_back(b);
            v[b].push_back(a);
            adjMatrix[a][b] = 1;
            adjMatrix[b][a] = 1;
        }
    }

    // Print adjacency list
    cout << "Adjacency List\n";
    for(int i=1;i<=vert;i++){
        cout << i << " : ";
        for(int j=0;j<v[i].size();j++){
            cout << v[i][j] << " ";
        }
        cout << "\n";
    }

    // Print adjacency matrix
    cout << "\nAdjacency Matrix\n";
    for(int i=1;i<=vert;i++){
        for(int j=1;j<=vert;j++){
            cout << adjMatrix[i][j] << " ";
        }
        cout << "\n";
    }

    cout << "\nThe output of DFS:\n";
    dfs(1);

    cout << "\nThe output of BFS:\n";
    init(vert);
    bfs(1);

    return 0;
}
