#include <bits/stdc++.h>
using namespace std;

long long bigmod(long long a, long long b, long long mod) {
    long long result = 1;
    a %= mod;

    while (b > 0) {
        if (b & 1)
            result = (result * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return result;
}

int main() {
    long long a, b, mod;
    cin >> a >> b >> mod;
    cout << bigmod(a, b, mod);
    return 0;
}




/*
🔗 Practice Problems

Codeforces

https://codeforces.com/problemset/problem/742/A

https://codeforces.com/problemset/problem/271/A




LeetCode

https://leetcode.com/problems/powx-n/

https://leetcode.com/problems/super-pow/
*/
