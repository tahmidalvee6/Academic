#include<bits/stdc++.h>
using namespace std;

int adjMatrix[100][100];

int main(){
    int vert, e;
    cin >> vert >> e;

    for(int i=1;i<=vert;i++){
        for(int j=1;j<=vert;j++){
            adjMatrix[i][j] = 0;
        }
    }

    for(int i=0;i<e;i++){
        int a,b;
        cin >> a >> b;
        adjMatrix[a][b] = 1;
        adjMatrix[b][a] = 1;
    }

    cout << "Adjacency Matrix\n";
    for(int i=1;i<=vert;i++){
        for(int j=1;j<=vert;j++){
            cout << adjMatrix[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
