#include<bits/stdc++.h>
using namespace std;

void primeFactorization(int N) {
    for (int i = 2; i <= N; i++) {
        if (N % i == 0) {
            int exp = 0;
            while(N % i == 0) {
                exp++;
                N /= i;
            }
            cout << i << "^" << exp << endl;
        }
    }
    if (N > 1) {
        cout << N << "^" << 1 << endl;
    }
}

int main(){
    int n; cin >> n;
    primeFactorization(n);
    return 0;
}