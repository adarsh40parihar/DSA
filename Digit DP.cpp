#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/number-of-digit-one/

#define ll long long
ll dp[20][2][20]; // index,tight,count

ll solve(ll i, ll tight, ll cnt, string &s, int k)
{
    if (i == s.size())
        return cnt;

    if (dp[i][tight][cnt] != -1)
        return dp[i][tight][cnt];

    ll limit = (tight == 1) ? s[i] - '0' : 9;
    ll ans = 0;
    for (ll j = 0; j <= limit; j++)
    {
        ll updCnt = cnt + (j == k ? 1 : 0);
        ans += solve(i + 1, tight & (j == s[i] - '0'), updCnt, s, k);
    }
    return dp[i][tight][cnt] = ans;
}

int countDigitOne(int n)
{
    string s = to_string(n);
    memset(dp, -1, sizeof(dp));
    int k = 1;
    ll ans = solve(0, 1, 0, s, k);
    return ans;
}