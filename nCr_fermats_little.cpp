/*******************************************************
 * Fermat’s Little Theorem Template (Parameterized)
 * Author: Adarsh (Buddy)
 * Use: Modular inverse + nCr under prime MOD
 *******************************************************/

#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int MOD = 1e9 + 7; // must be prime

// ------------------ Fast Power ------------------
ll power(ll x, ll n)
{
    x %= MOD; // always reduce base first
    if (n == 0)
        return 1;
    if (n == 1)
        return x;
    ll half = power((x * x) % MOD, n / 2); // square and mod safely
    if (n & 1)
        return (half * x) % MOD;
    return half;
}

// ------------------ Modular Inverse ------------------
ll modInverse(ll a, ll mod = MOD)
{
    return power(a, mod - 2); // Fermat’s theorem
}

// ------------------ Factorials + Inverses ------------------
vector<ll> fact, invFact;

// Passable version: precompute up to N
void precomputeFactorials(int N)
{
    fact.assign(N + 1, 1);
    invFact.assign(N + 1, 1);

    for (int i = 1; i <= N; i++)
        fact[i] = (fact[i - 1] * i) % MOD;

    invFact[N] = modInverse(fact[N]);
    for (int i = N - 1; i >= 0; i--)
        invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
}

// ------------------ nCr Function ------------------
ll nCr(ll n, ll r)
{
    if (r < 0 || r > n)
        return 0;
    return (((fact[n] * invFact[r]) % MOD) * invFact[n - r]) % MOD;
}

// ------------------ Example Usage ------------------
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N = 1e6;             // or as required by your problem
    precomputeFactorials(N); // O(N)

    ll n = 10, r = 3;
    cout << "nCr(" << n << "," << r << ") mod " << MOD << " = " << nCr(n, r) << "\n";

    cout << "Inverse of 5 mod " << MOD << " = " << modInverse(5) << "\n";
    cout << "2^10 mod " << MOD << " = " << power(2, 10) << "\n";

    return 0;
}
