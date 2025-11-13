// Merging Sort

// suppose amdr 2 ta array deya ase
// 1 3 5 7..... odd num er array
// 2 4 6 8.... even num er array
// ei 2 ta e kintu sorted ase 
// merging er kaj hosse 2 ta array k sort kore akta array te convert kore deya
// 1 2 3 4 5 6 7 8
// 2 ta array k merge kore amdr 3 num array ta dibe



#include<bits/stdc++.h>
using namespace std;

void MERGE(int A[], int R, int B[], int S, int C[]) {
    int NA = 0, NB = 0, PTR = 0;
    while(NA < R && NB < S) {
        if(A[NA] < B[NB]) {
            C[PTR] = A[NA];
            PTR++;
            NA++;
        }
        else {
            C[PTR] = B[NB];
            PTR++;
            NB++;
        }
    }

    if(NA == R) {
        for(int k = 0; k < S - NB; k++) {
            C[PTR + k] = B[NB + k];
        }
    }
    else {
        for(int k = 0; k < S - NA; k++) {
            C[PTR + k] = A[NA + k];
        }
    }
}

int main() {
    const int R = 4, S = 4;     // 2 ta array er size nilam
    int A[R] = {1,3,5,7};
    int B[S] = {2,4,6,8};
    int C[R + S];

    MERGE(A,R,B,S,C);

    for(int i = 0; i < S + R; i++) {
        cout<<C[i]<<" ";
    }
}

