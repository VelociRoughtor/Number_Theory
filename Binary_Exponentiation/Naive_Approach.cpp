#include<bits/stdc++.h>
using namespace std;

int power(int base, int exp) {
    int res = 1;
    for (int i = 1; i <= exp; i++) {
        res *= base;
    }
    return res;
}

int main(){
    int x, n; cin >> x >> n;
    int res = power(x, n);
    cout << res << endl;
    return 0;
}