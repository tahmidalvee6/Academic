// Insertion Sort


#include<bits/stdc++.h>
using namespace std;

void INSERTION(int A[], int n) {
    A[0] = INT_MIN;
    for(int k = 2; k < n; k++) {
        int TEMP = A[k], PTR = k - 1;
        
        while(TEMP < A[PTR]) {
            A[PTR + 1] = A[PTR];
            PTR--;
        }
        A[PTR + 1] = TEMP;
    }
}


int main() {
    int n = 7;              // amdr element hosse 6 ta...bt amdr algorithm notation e akta minus infinity rakhtese...shei jnno 1 ta barai nisi
    int A[n] = {INT_MIN, 12,15,6,18,24,3};

    for(int i = 1; i < n; i++) {            // eikhane amra 1 theke start krbo...jate minus infinity ta na print hoy....main element gula e print hok
        cout<<A[i]<<" ";
    }
    cout<<endl;

    INSERTION(A, n);

    for(int i = 1; i < n; i++) {
        cout<<A[i]<<" ";
    }
    cout<<endl;
}
