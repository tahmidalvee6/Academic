// Linear search in 2D array

#include<iostream>
using namespace std;
int main() {
    int r,c; 
    cin>>r>>c;

    int arr[r][c];

    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cin>>arr[i][j];
        }
    }

    int x;
    cin>>x;

    int f = 0; 

    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            if(arr[i][j] == x) {
                f = 1;
            }
        }
    }

    if(f) {
        cout<<"Found"<<endl;
    }
    else {
        cout<<"Not Found"<<endl;
    }
}


// Time Complexity :
// Best Case : O(1)
// Worst Case : O(m * n)

