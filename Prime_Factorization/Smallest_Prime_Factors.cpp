#include <bits/stdc++.h>
using namespace std;

const int N = 1000000;
vector<int> spf(N + 1); 

void sieve() {
    for (int i = 1; i <= N; i++) spf[i] = i;

    for (int i = 2; i * i <= N; i++) {
        if (spf[i] == i) { 
            for (int j = i * i; j <= N; j += i) {
                if (spf[j] == j) { 
                    spf[j] = i;
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    sieve();    
    int q; cin >> q;
    
    while (q--) {
        int n; cin >> n;
        if (n < 2) {
            cout << "Can't perform prime factorization\n";
        }
        while (n > 1) {
            cout << spf[n] << ' ';
            n /= spf[n];
        }
        cout << '\n';
    }

    return 0;
}
