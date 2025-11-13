// Selection Sort


// amdr kase jdi onk gula element thake...
// 77 33 44 11 88 22 66 55
// eikhane amra first element ta dhorbo...erpr chck krbo 77 shoho bkigular modde shb chaye choto element konta...eikhane 11
// tai 11 ta 77 er jaegae niye ashbo r 77  ta k 11 er jaegae niye jabo
// akhn amdr array ta hbe ... 11 33 44 77 88 22 66 55... eikhane amdr first element mane 11 ta sorted
// tai er porer pass 33 k first dhorbo...erpr 33 shoho bkigular modde chck krbo konta choto...choto paisi 22
// akhn 22 k 33 er jaegae diye dibo r 33 k 22 er jaegae
// akhn amdr array ta hbe ... 11 22 44 77 88 33 66 55... eikhane amdr first element mane 11 22 duita sorted




#include<bits/stdc++.h>
using namespace std;

int MIN(int A[], int k, int N) {                     // int function banaisi karon ei function LOC ta return krbe
    int minval = A[k], LOC  = k;                    // dhore nissi first val ta e minimum value ta r first element er location ta e hosse minimum val er loc
    for(int j = k; j < N; j++) {
        if(A[j] < minval) {
            minval = A[j];
            LOC = j;
        }
    }
    return LOC;
}


void Selection(int A[], int N) {
    for(int k = 0; k < N - 1; k++) {       // akta loop chalabo ja 0 theke N - 1 pojjonto cholbe...N - 1 karon amdr last element er shte r kisu compare kora lagbe na...bki gula sort korar por oita e last sorted element hoye jabe
        int LOC = MIN(A, k, N);            // min val ta find out korte arekta funciton k call dissi... min val ta LOC variable e store thakbe

        // akhn amra min val tar sthe k er current pos ta swap kore dibo
        int TEMP = A[k];                // k er current pos er val ta amra TEMP variable e rakhsi
        A[k] = A[LOC];
        A[LOC] = TEMP;

    }
}

int main() {
    int n;
    cin>>n;

    int A[n];
    for(int i = 0; i < n; i++) {
        cin>>A[i];
    }

    Selection(A, n);                    // selection function re call krsi

    for(int i = 0; i < n; i++) {
        cout<<A[i]<<" ";
    }
    cout<<endl;
}
