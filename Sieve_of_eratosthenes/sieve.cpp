#include<bits/stdc++.h>
using namespace std;

const int N = 90000000;
vector<bool> isPrime(N + 1, true);
vector<int> primes;

void sieve(){
    isPrime[0] = false;
    isPrime[1] = false;
    for (int i = 2; i * i <= N; i++) {
        if(isPrime[i]) {
            for (int j = i * i; j <= N; j += i) {
                isPrime[j] = false;
            }
        }
    }
    for (int i = 2; i <= N; i++) {
        if(isPrime[i]) {
            primes.push_back(i);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    sieve();    
    int q; cin >> q;
    while(q--) {
        int n; cin >> n;
        cout << primes[n - 1] << endl;
    }
    
    return 0;
}
