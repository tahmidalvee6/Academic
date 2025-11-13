#include<iostream>
using namespace std;
int main(){

 freopen("in.txt","r",stdin);
 freopen("out4.txt","w",stdout);

 int n;
 cin >> n;
 
 for(int i=1; i<=n ;i++){
    cout << rand()%5000<<endl;
 }
}
