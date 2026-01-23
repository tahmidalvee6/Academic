#include<bits/stdc++.h>
using namespace std;

int cost[100][100];
int vis[100];

int main(){
    int n,e;
    cin>>n>>e;

    // initialize cost matrix
    for(int i=1;i<=n;i++) {
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
    

    vis[1]=1;   // start from node 1
    int total=0;

    for(int k=1;k<n;k++){
        int mn=INT_MAX, a=-1, b=-1;        // mn = INT_MAX mane shurute amra dhore ni kono edge paoya jae nai...mane minimum edge e infinity....a hosse source node ba visited node r -1 hossse shurute kono node select kori nai

        for(int i=1;i<=n;i++){
            if(vis[i]){
                for(int j=1;j<=n;j++){
                    if(!vis[j] && cost[i][j]<mn){
                        mn=cost[i][j];
                        a=i; b=j;
                    }
                }
            }
        }

        vis[b]=1;
        total+=mn;
        cout<<a<<" - "<<b<<" : "<<mn<<"\n";
    }

    cout<<"Total cost = "<<total<<"\n";
    return 0;
}




/*

Input :
5 7
1 2 2
1 3 3
2 3 1
2 4 4
3 4 5
3 5 6
4 5 7




Expected Output :
1 - 2 : 2
2 - 3 : 1
2 - 4 : 4
3 - 5 : 6
Total cost = 13

*/
