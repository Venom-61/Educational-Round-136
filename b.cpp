#include<bits/stdc++.h>
using namespace std;

#define ll long long

// B. Array Recovery

void solve() {
    int n;
    cin >> n;
    vector<int> d(n + 1);
    for(int i = 1; i <= n; i++) 
        cin >> d[i];

    bool ok = true;
    vector<int> a(2);
    a[1] = d[1];

    for(int i = 2; i <= n; i++) {
        a.push_back(d[i] + a[i-1]);
        if(d[i] != 0 and a[i-1] - d[i] >= 0)
            ok = false;
    }

    if(ok) {
        for(int i = 1; i <= n; i++)
            cout << a[i] << " ";
        cout << "\n";
    } else 
        cout << "-1\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int test = 1;
    cin >> test;
    while(test--) {
        solve();
    }

    return 0;
}
