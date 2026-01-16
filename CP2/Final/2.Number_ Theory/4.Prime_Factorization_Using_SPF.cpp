#include <bits/stdc++.h>
using namespace std;

const int N = 1000000;
int spf[N + 1];

void sieveSPF() {
    for (int i = 1; i <= N; i++)
        spf[i] = i;

    for (int i = 2; i * i <= N; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j <= N; j += i) {
                if (spf[j] == j)
                    spf[j] = i;
            }
        }
    }
}

int main() {
    sieveSPF();

    int n;
    cin >> n;

    while (n != 1) {
        cout << spf[n] << " ";
        n /= spf[n];
    }

    return 0;
}





/*
🔗 Practice Problems

Codeforces

https://codeforces.com/problemset/problem/1034/A

https://codeforces.com/problemset/problem/17/A



LeetCode

https://leetcode.com/problems/count-primes/

https://leetcode.com/problems/ugly-number/
*/
