[题目](https://qoj.ac/contest/2521/problem/14511)

这是一道贪心,我们赛时想麻烦了,直接去暴搜了,导致一直T

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
using vevei = vector<vector<int>>;
using ai3 = array<int, 3>;


const double PI = acos(-1);

void init(){
    ;
}

void solve(){
    int n;
    cin >> n;
    vei a(n + 10);
    vevei v(4);
    F(i,1,n) {
        cin >> a[i];
        a[i] %= 4;
        v[a[i]].pb(i);
    }
    vei ans;
    int idx = 0;
    F(i,1,n){
        if(v[0].size()){
            ans.pb(v[0].back());
            v[0].pop_back();
            continue;
        }
        if(idx == 1){
            if(v[3].size()){
                ans.pb(v[3].back());
                v[3].pop_back();
                idx = 0;
                continue;
            }
            if(v[1].size()){
                ans.pb(v[1].back());
                v[1].pop_back();
                idx = 2;
                continue;
            }
            if(v[2].size()){
                ans.pb(v[2].back());
                v[2].pop_back();
                idx = 3;
                continue;
            }
        }else if(idx == 2){
            if(v[1].size()){
                ans.pb(v[1].back());
                v[1].pop_back();
                idx = 3;
                continue;
            }
            if(v[2].size()){
                ans.pb(v[2].back());
                v[2].pop_back();
                idx = 0;
                continue;
            }
        }else if(idx == 3){
            if(v[3].size()){
                ans.pb(v[3].back());
                v[3].pop_back();
                idx = 2;
                continue;
            }
            if(v[1].size()){
                ans.pb(v[1].back());
                v[1].pop_back();
                idx = 0;
                continue;
            }
        }else if(idx == 0){
            if(v[3].size()){
                ans.pb(v[3].back());
                v[3].pop_back();
                idx = 3;
                continue;
            }
            if(v[2].size()){
                ans.pb(v[2].back());
                v[2].pop_back();
                idx = 2;
                continue;
            }
        }
        cout << -1 << endl;
        return;
    }
    for(auto it : ans) cout << it << " ";
    cout << endl;
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