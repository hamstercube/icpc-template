[例题](https://www.luogu.com.cn/problem/P2629)

```cpp
#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define all(a) a.begin(), a.end()
#define endl '\n'
//#define int long long
#define lb(v,x) (int)(lower_bound(all(v),x)-v.begin())
#define ub(v,x) (int)(upper_bound(all(v),x)-v.begin())
#define lowbit(x) (x & -x)
#define F(i, x, y) for (int i = (x); i <= (y); i++)
#define DF(i, x, y) for (int i = (x); i >= (y); i--)
#define debug(x) cout << #x << ": " << x << endl;
#define ihb(x) ((x) == 0 ? -1 : (31 - __builtin_clz((x)))) // 最高1位子,0开始
#define lhb(x) ((x) == 0 ? -1 : (63 - __builtin_clzll((x))))
#define ione __builtin_popcount // 1的个数
#define lone __builtin_popcountll 

template<class T1, class T2> bool cmin(T1 &x, const T2 &y) { if (y < x) { x = y; return 1; } return 0; }
template<class T1, class T2> bool cmax(T1 &x, const T2 &y) { if (x < y) { x = y; return 1; } return 0; }

using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using PII = pair<int, int>;
using PLL = pair<ll, ll>;
using vei = vector<int>;
using veb = vector<bool>;
using vevei = vector<vector<int>>;
using ai3 = array<int, 3>;


const double PI = acos(-1);

void init(){
    ;
}

要证明k到n每一步都大于等于0,只要证明最小的i(>=k , <=n)到k大于0即可,反之亦然 (贪心?好像是)

void solve(){
    int n;
    cin >> n;
    vei a(n + 10);
    F(i,1,n){
        cin >> a[i];
        a[i] += a[i - 1];
    }
    vevei q(2, vei(n + 10));
    F(i,1,n){
        if(i == 1) q[0][i] = a[i];
        else q[0][i] = min(a[i], q[0][i - 1]);
    }
    DF(i,n,1){
        if(i == n) q[1][i] = a[i];
        else q[1][i] = min(a[i], q[1][i + 1]);
    }
    // for(int i = 1; i <= n; i ++) cout << q[0][i] << " ";
    // cout << endl;
    int ans = 0;
    F(i,1,n){
        int r = q[1][i] - a[i - 1];
        //debug(r);
        // debug(a[i - 1]);
        if(r >= 0){
            int l = (a[n] - a[i - 1] + q[0][i - 1]);
            if(l >= 0) ans ++;
        }
    }
    cout << ans << endl;
    return;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    init();
    
    int _ = 1;
    // cin >> _;
    while (_--) solve();
    return 0;
}
```