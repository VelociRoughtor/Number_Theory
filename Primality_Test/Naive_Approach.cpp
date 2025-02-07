#include<bits/stdc++.h>
using namespace std;

bool isPrime(int n) {
    if (n < 2) {
        return true;
    }
    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main(){
    int n; cin >> n;
    if (isPrime(n)) {
        cout << n << " is Prime\n";
    } else {
        cout << n << " is Non-Prime\n";
    }
    return 0;
}