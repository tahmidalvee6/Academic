#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main() {
    int n;
    cin >> n;

    if (isPrime(n))
        cout << "Prime";
    else
        cout << "Not Prime";

    return 0;
}




/*
Codeforces

https://codeforces.com/problemset/problem/230/B

https://codeforces.com/problemset/problem/26/A



LeetCode

https://leetcode.com/problems/prime-number-of-set-bits-in-binary-representation/

https://leetcode.com/problems/count-primes/
*/
