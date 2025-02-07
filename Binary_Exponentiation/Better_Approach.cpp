#include<bits/stdc++.h>
using namespace std;

int power(int base, int exp) {
    int res = 1;
    while(exp) {
        if (exp & 1) res *= base;
        base *= base;
        exp >>= 1;
    }
    return res;
}

int main(){
    int x, n; cin >> x >> n;
    int res = power(x, n);
    cout << res << endl;
    return 0;
}