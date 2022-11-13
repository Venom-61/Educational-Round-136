#include<bits/stdc++.h>
using namespace std;

#define ll long long

// C. Card Game

// Combinatoric Starts here .....
// **Don't forget** to call init() in your std::main() function

const int maxA = 60;
const int MOD = (int) 998244353;

int N, a, b;
ll fact[maxA + 1], inv[maxA + 1];

ll inverse(ll x) {
    ll res = 1;
    ll expo = MOD - 2;
    while(expo > 0) {
        if(expo & 1) 
            res = (res * x) % MOD;
        x = (x * x) % MOD;
        expo >>= 1;
    }
    return res;
}

void init() {
    fact[0] = inv[0] = 1;    
    for(int i = 1; i <= maxA; i++) {
        fact[i] = (i * fact[i-1]) % MOD;
        inv[i] = inverse(fact[i]);
    }
}

ll nCr(ll n, ll r) {
    if(r > n or n < 0 or r < 0) 
        return 0;
    ll res = (fact[n] * inv[r]) % MOD;
    return (res * inv[n-r]) % MOD;
}

ll nPr(ll n, ll r) {
    return (nCr(n, r) * fact[r]) % MOD;
}

// Combinatorics ends here.....

void solve(int n, vector<vector<ll> >& dp) {
    if(n == 2)
        return;

    solve(n-2, dp);

    dp[n][0] = (nCr(n-1, n/2) + dp[n-2][1]) % MOD;
    dp[n][1] = (nCr(n-2, n/2) + dp[n-2][0]) % MOD;
    dp[n][2] = (dp[n-2][2]) % MOD;
}

void solve() {
    ll n;
    cin >> n;
    vector<vector<ll> > dp(n+1, vector<ll>(3, -1));

    // Base Cases
    dp[2][0] = 1; // Alex Wins
    dp[2][1] = 0; // Boris Wins
    dp[2][2] = 1; // draw

    solve(n, dp);
    cout << dp[n][0] << " " << dp[n][1] << " " << dp[n][2] << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    init();

    int test = 1;
    cin >> test;
    while(test--) {
        solve();
    }

    return 0;
}
