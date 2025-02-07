#include <bits/stdc++.h>

using namespace std;

const int N = 1000000; 
vector<bool> isPrime;
vector<int> primes;
vector<int> prePrime;
vector<int> primePrime;

void sieve() {
    isPrime.assign(N + 1, true);
    prePrime.assign(N + 1, 0);
    primePrime.assign(N + 1, 0);
    
    isPrime[0] = false;
    isPrime[1] = false;

    for (int i = 2; i * i <= N; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= N; j += i) {
                isPrime[j] = false;
            }
        }
    }

    int primeCount = 0;
    for (int i = 1; i <= N; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
            primeCount++;
        }
        prePrime[i] = primeCount;
    }

    int cnt = 0;
    for (int i = 1; i <= N; i++) {
        if (isPrime[prePrime[i]]) {
            cnt++;
        }
        primePrime[i] = cnt;
    }
}

void solve() {
    int l, r;
    cin >> l >> r;
    cout << primePrime[r] - primePrime[l - 1] << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    sieve();

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
