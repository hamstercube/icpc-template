
```cpp
#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef unsigned long long ull;

ll ans = 0;
ll len[6010][6010];
ll dp[6010];
ll i, j, n, m;
string s;

void init(){
    for(ll i = 1; i <= n; i++){
        for(ll j = 1; j <= n; j++){
            len[i][j] = -1e6;
        }
        dp[i] = 1;
    }
}

void solve(){
    ll ans = 1;
    cin >> n >> s;
    s = " "+s;
    init();
    for(ll i = n; i >= 1; i--){   //求二维求最大lcp
        for(ll j = i-1 ; j >= 1; j--){
            if(s[i]==s[j]){
                len[j][i] = max(1, len[j+1][i+1]+1);
            }
        }
    }
    for(ll i = n-1; i >= 1 ; i--){
        for(ll j = i+1; j <= n; j++){
            if(len[i][j] >= dp[j]){
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    init();
    ll T;
    cin >> T;
    while(T--) solve();
    return 0;
}
```