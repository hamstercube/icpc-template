[题目](https://qoj.ac/contest/2521/problem/14508)

贪心,当时主要卡在边界的处理,还有前面的cha的计算与使用


```cpp
#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define all(a) a.begin(), a.end()
#define endl '\n'
#define int long long
#define lb(v,x) (int)(lower_bound(all(v),x)-v.begin())
#define ub(v,x) (int)(upper_bound(all(v),x)-v.begin())
#define lowbit(x) (x & -x)
#define F(i, x, y) for (int i = (x); i <= (y); i++)
#define DF(i, x, y) for (int i = (x); i >= (y); i--)
#define debug(x) cout << #x << ": " << x << endl;
#define ihb(x) ((x) == 0 ? -1 : (31 - __builtin_clz((x)))) // 最高1
#define lhb(x) ((x) == 0 ? -1 : (63 - __builtin_clzll((x))))
#define ione __builtin_popcount 
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
using vevei = vector<vector<int>>;


const double PI = acos(-1);

void init(){
    ;
}


void solve(){
    int n;
    cin >> n;
    vei a(n + 10), hz(n + 10);
    F(i,1,n) cin >> a[i];
    DF(i,n,1){
        int t = a[i] - i;
        if(t < 0){
            cout << -1 << endl;
            return;
        }
        if(i == n) hz[i] = t;
        else hz[i] = min(hz[i + 1], t);
    }
    int add = 0;
    int ans = n;
    int cha = 0;
    int jm = 0;
    for(int i = 1; i <= n; i ++){
        int ii = i + add;
        //debug(hz[i + 1]);
        if(a[i] > ii && (add < hz[i])){
            int k = min(a[i] - ii, hz[i] - add);
            cmax(k,0ll);
            //debug(k);
            add += k;
            ans += k;
            ii += k;
            if(cha){
                ans -= min(cha,k);
                cha -= min(cha,k);
            }
        }
        //debug(ii);
        ans += max(0ll,a[i] - ii);
        cha += max(0ll,a[i] - ii);
        //debug(ans);
    }
    cout << ans << endl;
    return;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    init();
    
    int _ = 1;
     cin >> _;
    while (_--) solve();
    return 0;
}
```