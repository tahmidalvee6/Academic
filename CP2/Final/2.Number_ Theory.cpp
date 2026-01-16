#include <bits/stdc++.h>
using namespace std;

/* =====================================================
   1️⃣ PRIMALITY CHECK
   ===================================================== */

// Basic Primality Check (O(n))
bool isPrime_basic(int n) {
    if (n <= 1) return false;
    for (int i = 2; i < n; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

// Optimized Primality Check (O(sqrt(n)))
bool isPrime_sqrt(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

// Advanced Primality Check (6k ± 1)
bool isPrime_advanced(long long n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;

    for (long long i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}

/* =====================================================
   2️⃣ PRIME FACTORIZATION
   ===================================================== */

// Basic Prime Factorization
void primeFactor_basic(int n) {
    cout << "Prime Factors: ";
    for (int i = 2; i <= n; i++) {
        while (n % i == 0) {
            cout << i << " ";
            n /= i;
        }
    }
    cout << endl;
}

// Optimized Prime Factorization (sqrt(n))
void primeFactor_optimized(int n) {
    cout << "Prime Factors: ";
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            cout << i << " ";
            n /= i;
        }
    }
    if (n > 1)
        cout << n;
    cout << endl;
}

/* =====================================================
   3️⃣ SIEVE OF ERATOSTHENES
   ===================================================== */

// Simple Sieve
void sieve_simple(int n) {
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= n; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i)
                isPrime[j] = false;
        }
    }

    cout << "Primes up to " << n << ": ";
    for (int i = 2; i <= n; i++) {
        if (isPrime[i])
            cout << i << " ";
    }
    cout << endl;
}

// Sieve with Smallest Prime Factor (SPF)
const int MAXN = 1000000;
int spf[MAXN + 1];

void sieve_spf() {
    for (int i = 1; i <= MAXN; i++)
        spf[i] = i;

    for (int i = 2; i * i <= MAXN; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j <= MAXN; j += i) {
                if (spf[j] == j)
                    spf[j] = i;
            }
        }
    }
}

void primeFactor_using_spf(int n) {
    cout << "Prime Factors using SPF: ";
    while (n != 1) {
        cout << spf[n] << " ";
        n /= spf[n];
    }
    cout << endl;
}

/* =====================================================
   4️⃣ BIGMOD (MODULAR EXPONENTIATION)
   ===================================================== */

// Normal Power (Inefficient)
long long power_basic(long long a, long long b) {
    long long result = 1;
    for (int i = 1; i <= b; i++)
        result *= a;
    return result;
}

// Fast Modular Exponentiation (Iterative)
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

// Recursive Bigmod
long long bigmod_recursive(long long a, long long b, long long mod) {
    if (b == 0) return 1;
    long long x = bigmod_recursive(a, b / 2, mod);
    x = (x * x) % mod;
    if (b % 2)
        x = (x * a) % mod;
    return x;
}

/* =====================================================
   MAIN FUNCTION
   ===================================================== */

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    // Primality Check
    cout << "\n--- Primality Check ---\n";
    cout << "Basic: " << (isPrime_basic(n) ? "Prime" : "Not Prime") << endl;
    cout << "Optimized: " << (isPrime_sqrt(n) ? "Prime" : "Not Prime") << endl;
    cout << "Advanced: " << (isPrime_advanced(n) ? "Prime" : "Not Prime") << endl;

    // Prime Factorization
    cout << "\n--- Prime Factorization ---\n";
    primeFactor_basic(n);
    primeFactor_optimized(n);

    // Sieve
    cout << "\n--- Sieve of Eratosthenes ---\n";
    sieve_simple(n);

    sieve_spf();
    if (n <= MAXN)
        primeFactor_using_spf(n);

    // Bigmod
    cout << "\n--- Bigmod ---\n";
    long long a, b, mod;
    cout << "Enter a, b, mod: ";
    cin >> a >> b >> mod;

    cout << "Bigmod (Iterative): " << bigmod(a, b, mod) << endl;
    cout << "Bigmod (Recursive): " << bigmod_recursive(a, b, mod) << endl;

    return 0;
}





/*
📌 Codeforces Practice Problems
🔹 Primality / Factorization

https://codeforces.com/problemset/problem/230/B

https://codeforces.com/problemset/problem/26/A

https://codeforces.com/problemset/problem/1033/A

🔹 Sieve

https://codeforces.com/problemset/problem/919/B

https://codeforces.com/problemset/problem/776/B

🔹 Bigmod / Modular Arithmetic

https://codeforces.com/problemset/problem/271/A

https://codeforces.com/problemset/problem/742/A

https://codeforces.com/problemset/problem/427/A




📌 LeetCode Practice Problems
🔹 Primality / Sieve

https://leetcode.com/problems/count-primes/

https://leetcode.com/problems/prime-number-of-set-bits-in-binary-representation/

🔹 Factorization

https://leetcode.com/problems/ugly-number/

https://leetcode.com/problems/ugly-number-ii/

🔹 Bigmod / Power

https://leetcode.com/problems/powx-n/

https://leetcode.com/problems/super-pow/
*/
