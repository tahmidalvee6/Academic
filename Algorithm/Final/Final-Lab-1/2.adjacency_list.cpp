#include<bits/stdc++.h>
using namespace std;


int main(){

freopen("in.txt","r",stdin);

int vert,e;
cin>>vert>>e;
vector<int> v[vert+1];
for(int i=0;i<e;i++){
    //int a,b;
    char x,y;
    int a,b;
    cin>>x>>y;
    a= x-'a';
    b= y-'a';

    if(a==b){v[a].push_back(b);}
    else{
        v[a].push_back(b);
        v[b].push_back(a);
    }
}
//vector output
for(int i=0;i<vert;i++){
    char c= i+'a';
    cout<<c<<" : ";
    for(int j=0;j<v[i].size();j++){
        //c = v[i][j]+'a';
        //cout<<c<<" ";
        printf("%c ", v[i][j]+'a');
    }
    cout<<"\n";
}



return 0;
}



