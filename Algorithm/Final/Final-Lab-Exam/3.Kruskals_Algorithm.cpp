#include<bits/stdc++.h>
using namespace std;

struct Edge{
    int u,v,w;
};

Edge edges[100];
int parent[100];

int find(int x){
    if(parent[x]==x) return x;
    return find(parent[x]);
}

int main(){
    int n,e;
    cin>>n>>e;

    for(int i=0;i<e;i++)
        cin>>edges[i].u>>edges[i].v>>edges[i].w;

    for(int i=1;i<=n;i++)
        parent[i]=i;

    // sort edges by weight
    for(int i=0;i<e;i++){
        for(int j=i+1;j<e;j++){
            if(edges[i].w > edges[j].w)
                swap(edges[i],edges[j]);
        }
    }

    int total=0;

    for(int i=0;i<e;i++){
        int a=find(edges[i].u);
        int b=find(edges[i].v);

        if(a!=b){
            parent[a]=b;
            total+=edges[i].w;
            cout<<edges[i].u<<" - "<<edges[i].v<<" : "<<edges[i].w<<"\n";
        }
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
2 - 3 : 1
1 - 2 : 2
2 - 4 : 4
3 - 5 : 6
Total cost = 13

*/
