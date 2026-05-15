
```cpp
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll i, j, n, m;
string s;
bool f[5010][5010];
ll dp[5010];
ll mod = 998244353;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> s;
    n = s.size();
    s = " "+s;
    for(ll i = 1; i <= n; i++){
        vector<ll> ne(n+5);
        ne[i] = i;
        f[i][i] = 1;
        for(ll j = i+1, h = i; j <= n; j++){
            while(s[j] != s[h] && h != i) h = ne[h-1];
            if(s[j] == s[h]) h++;
            ne[j] = h;
            ll len = j-i+1, t = len-(ne[j]-i);
            if(len%t == 0 && len != t) f[i][j] = 0; //求最大循环子串
            else f[i][j] = 1;
//              cout << i << " " << j << " " << f[i][j] << endl;
        }
    }
    dp[0] = 1;
    for(ll i = 0; i < n; i++){
        for(ll j = i+1; j <= n; j++){
            if(f[i+1][j]) dp[j] += dp[i], dp[j] %= mod;
        }
    }
    cout << dp[n] << endl;
    return 0;
};
```