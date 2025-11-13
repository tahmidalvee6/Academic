// Bubble sort in 2D array

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

    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            for(int k = 0; k < c - j - 1; k++) {
                if(arr[i][k] > arr[i][k + 1]) {
                    int temp = arr[i][k];
                    arr[i][k] = arr[i][k + 1];
                    arr[i][k + 1] = temp;
                }
            }
        }
    }

    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

// Time Complexity :
// Best Case : O(m * n)
// Worst Case : O((m * n)^2)


