#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;

    bool prime = true;

    if (n <= 1) {
        prime = false;
    } 
    else {
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                prime = false;
                break;
            }
        }
    }

    if (prime) {
        cout<<"Prime";
    }
    else {
        cout<<"Not Prime";
    }
}


/*

Input
7


Output
Prime

*/


/*
Codeforces

https://codeforces.com/problemset/problem/230/B

https://codeforces.com/problemset/problem/26/A



LeetCode

https://leetcode.com/problems/prime-number-of-set-bits-in-binary-representation/

https://leetcode.com/problems/count-primes/
*/
