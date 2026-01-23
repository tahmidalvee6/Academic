#include<bits/stdc++.h>
using namespace std;

int cost[100][100], dist[100], vis[100];                    // dist hosse source node theke durotto



int main(){
    int n,e;
    cin>>n>>e;

    for(int i=1;i<=n;i++){
        dist[i]=INT_MAX;
        for(int j=1;j<=n;j++) {
            cost[i][j]=INT_MAX;
        }
    }

    for(int i=0;i<e;i++){
        int u,v,w;
        cin>>u>>v>>w;
        cost[u][v]=w;
        cost[v][u]=w;
    }

    dist[1]=0;

    for(int k=1;k<=n;k++){
        int mn=INT_MAX, u=-1;

        for(int i=1;i<=n;i++){
            if(!vis[i] && dist[i]<mn){
                mn=dist[i];
                u=i;
            }
        }

        vis[u]=1;

        for(int v=1;v<=n;v++){
            if(cost[u][v]!=INT_MAX && dist[v]>dist[u]+cost[u][v]){
                dist[v]=dist[u]+cost[u][v];
            }
        }
    }

    for(int i=1;i<=n;i++)
        cout<<"1 -> "<<i<<" = "<<dist[i]<<"\n";

    return 0;
}



/*
Input :
5 7
1 2 2
1 3 4
2 3 1
2 4 7
3 5 3
4 5 1
3 4 2





Expected Output :
1 -> 1 = 0
1 -> 2 = 2
1 -> 3 = 3
1 -> 4 = 5
1 -> 5 = 6

*/
