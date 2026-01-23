#include<bits/stdc++.h>
using namespace std;

vector<int> v[100];

int main(){
    int vert, e;
    cin >> vert >> e;

    for(int i=0;i<e;i++){
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);   // undirected graph
    }

    cout << "Adjacency List\n";
    for(int i=1;i<=vert;i++){
        cout << i << " : ";
        for(int j=0;j<v[i].size();j++){
            cout << v[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
