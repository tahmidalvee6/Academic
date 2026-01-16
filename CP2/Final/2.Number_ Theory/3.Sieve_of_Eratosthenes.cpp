#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= n; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i)
                isPrime[j] = false;
        }
    }

    for (int i = 2; i <= n; i++) {
        if (isPrime[i])
            cout << i << " ";
    }
    return 0;
}



/*
🔗 Practice Problems

Codeforces

https://codeforces.com/problemset/problem/776/B

https://codeforces.com/problemset/problem/919/B



LeetCode

https://leetcode.com/problems/count-primes/

https://leetcode.com/problems/find-prime-pairs-with-target-sum/
*/
