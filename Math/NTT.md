求两多项式取模相乘系数

输入系数ki：
多项式A = k0+k1*x+k2*x*x+k3*x*x*x

```cpp
#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
const int G = 3;
const int Gi = 332748118; // 3 在模 998244353 下的逆元

int qpow(int a, int b) {
    int res = 1;
    while(b) {
        if(b & 1) res = 1LL * res * a % MOD;
        a = 1LL * a * a % MOD;
        b >>= 1;
    }
    return res;
}

void ntt(vector<int>& a, bool inv) {
    int n = a.size();
    // 位反转
    for(int i = 0, j = 0; i < n; i++) {
        if(i < j) swap(a[i], a[j]);
        for(int k = n >> 1; (j ^= k) < k; k >>= 1);
    }
    // 蝴蝶变换
    for(int mid = 1; mid < n; mid <<= 1) {
        int wn = qpow(inv ? Gi : G, (MOD-1)/(mid*2));
        for(int j = 0; j < n; j += mid*2) {
            int w = 1;
            for(int k = 0; k < mid; k++, w = 1LL*w*wn%MOD) {
                int x = a[j+k], y = 1LL*w*a[j+k+mid]%MOD;
                a[j+k] = (x + y) % MOD;
                a[j+k+mid] = (x - y + MOD) % MOD;
            }
        }
    }
    if(inv) {
        int invn = qpow(n, MOD-2);
        for(int& x : a) x = 1LL * x * invn % MOD;
    }
}

// 多项式卷积 C = A * B
vector<int> mul(vector<int> A, vector<int> B) {
    int len = 1;
    while(len < A.size() + B.size()) len <<= 1;
    A.resize(len); B.resize(len);
    ntt(A, 0); ntt(B, 0);
    for(int i = 0; i < len; i++) A[i] = 1LL * A[i] * B[i] % MOD;
    ntt(A, 1);
    return A;
}
```