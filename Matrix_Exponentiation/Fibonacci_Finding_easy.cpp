#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD 1000000007
#define v64 vector<ll>
#define vv64 vector<vector<ll>>
#define forn(i, n) for (ll i = 0; i < n; i++)

vv64 multi(vv64 &A, vv64 &B) {
    int n = A.size(), m = B[0].size(), p = B.size();
    vv64 C(n, v64(m, 0));
    forn(i, n) {
        forn(j, m) {
            forn(k, p) {
                C[i][j] = (C[i][j] + (A[i][k] * B[k][j]) % MOD) % MOD;
            }
        }
    }
    return C;
}

vv64 matExpo(vv64 mat, ll exp) {
    int n = mat.size();
    vv64 res = {{1, 0}, {0, 1}};
    while (exp) {
        if (exp & 1) res = multi(res, mat);
        mat = multi(mat, mat);
        exp >>= 1;
    }
    return res;
}

void solve() {
    ll A, B, n;
    cin >> A >> B >> n;
    if (n == 0) {
        cout << A % MOD << endl;
        return;
    }
    if (n == 1) {
        cout << B % MOD << endl;
        return;
    }
    vv64 mat = {{0, 1}, {1, 1}};
    vv64 t = matExpo(mat, n - 1);
    vv64 f = {{A}, {B}};
    vv64 ans = multi(t, f);
    cout << ans[1][0] % MOD << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
