#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> multi(vector<vector<int>> A, vector<vector<int>> B) {
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(B[0].size(), 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < B[0].size(); j++) {
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return C;
}

vector<vector<int>> mat_expo(vector<vector<int>> &mat, int exp) {
    int n = mat.size();
    vector<vector<int>> res(n, vector<int> (n, 0));
    for (int i = 0; i < n; i++) {
        res[i][i] = 1;
    }

    while(exp) {
        if (exp & 1) res = multi(res, mat);
        mat = multi(mat, mat);
        exp >>= 1;
    }

    return res;
}

int main(){
    int k; cin >> k;
    if (k < 2) {
        cout << "kth fibonacci number is : " << k << endl;
        return 0;
    }
    
    vector<vector<int>> mat = {{0, 1}, {1, 1}}, t, f = {{0}, {1}}, ans;
    
    t = mat_expo(mat, k - 1);
    ans = multi(t, f);

    cout << "kth fibonacci number is : " << ans[1][0] << endl;
    return 0;
}