// Linear seach in 1D array

#include<iostream>
using namespace std;
int main() {
    int n;
    cin>>n;

    int arr[n];

    for(int i = 0; i < n; i++) {
        cin>>arr[i];
    }

    int x;
    cin>>x;

    int f = 0;
    for(int i = 0; i < n; i++) {
        if(arr[i] == x) {
            f = 1;
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
// Worst Case : O(n)

