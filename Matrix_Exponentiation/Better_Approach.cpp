#include <bits/stdc++.h>
using namespace std;

#define v32 vector<int>
#define vv32 vector<vector<int>>

vv32 multi(vv32 A, vv32 B) {
    int n = A.size();
    vv32 C(n, v32(n, 0)); 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j]; 
            }
        }
    }
    return C;
}

vv32 result(vv32 v, int exp) {
    int n = v.size();
    vv32 res(n, v32(n, 0));
    
    for (int i = 0; i < n; i++) {
        res[i][i] = 1;
    }

    while (exp) {
        if (exp & 1) 
            res = multi(res, v);
        v = multi(v, v);
        exp >>= 1;
    }

    return res;
}

int main() {
    int n;
    cin >> n;
    vv32 mat(n, v32(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }

    int exp;
    cin >> exp;

    vv32 res = result(mat, exp);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << res[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}
