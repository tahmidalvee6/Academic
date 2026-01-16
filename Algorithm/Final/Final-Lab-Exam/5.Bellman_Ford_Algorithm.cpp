#include<bits/stdc++.h>
using namespace std;

struct Edge{
    int u,v,w;
};

Edge edges[100];
int dist[100];

int main(){
    int n,e;
    cin>>n>>e;

    for(int i=0;i<e;i++)
        cin>>edges[i].u>>edges[i].v>>edges[i].w;

    for(int i=1;i<=n;i++)
        dist[i]=INT_MAX;

    dist[1]=0;

    // relax edges n-1 times
    for(int i=1;i<=n-1;i++){
        for(int j=0;j<e;j++){
            int u=edges[j].u;
            int v=edges[j].v;
            int w=edges[j].w;

            if(dist[u]!=INT_MAX && dist[v]>dist[u]+w){
                dist[v]=dist[u]+w;
            }
        }
    }

    // check negative cycle
    for(int j=0;j<e;j++){
        int u=edges[j].u;
        int v=edges[j].v;
        int w=edges[j].w;
        if(dist[u]!=INT_MAX && dist[v]>dist[u]+w){
            cout<<"Negative cycle exists\n";
            return 0;
        }
    }

    for(int i=1;i<=n;i++)
        cout<<"1 -> "<<i<<" = "<<dist[i]<<"\n";

    return 0;
}



/*
Input :
5 8
1 2 4
1 3 5
2 3 -3
2 4 6
3 4 2
3 5 4
4 5 -2
2 5 8


Expected Output :
1 -> 1 = 0
1 -> 2 = 4
1 -> 3 = 1
1 -> 4 = 3
1 -> 5 = 1

*/
