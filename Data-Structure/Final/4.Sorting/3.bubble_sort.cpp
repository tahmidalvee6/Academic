// Bubble Sort

#include<bits/stdc++.h>
using namespace std;

void BUBBLE(int A[], int n) {
    for(int i = 1; i < n - 1; i++) {
        for(int j = 1; j < n - i; j++) {
            if(A[j] > A[j + 1]) {
                swap(A[j], A[j + 1]);
            }
        }
    }
}

int main() {
    int n = 7;  
    int A[n] = {INT_MIN, 12, 15, 6, 18, 24, 3};

    cout<<"Before Sorting:\n";
    for(int i = 1; i < n; i++) {
        cout << A[i] << " ";
    }
    cout<<endl;

    BUBBLE(A, n);

    cout << "After Sorting:\n";
    for(int i = 1; i < n; i++) {
        cout<<A[i]<<" ";
    }
    cout<<endl;
}
