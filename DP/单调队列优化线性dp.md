[例题](https://www.luogu.com.cn/problem/P3957)

既然每次要继承前面最大的dp,那就队列优化

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
using vep = vector<PII>;
using vevei = vector<vector<int>>;
using ai3 = array<int, 3>;


const double PI = acos(-1);

void init(){
    ;
}

void solve(){
    int n,dd,k;
    cin >> n >> dd >> k;
    vep a(n + 10);
    F(i,1,n){
        int x,y;
        cin >> x >> y;
        a[i] = {x,y};
    }
    int l = 0, r = k + 1;
    auto check = [&](int x) -> bool{
        int d = max(1ll, dd - x);
        int u = x + dd;
        vei dp(n + 10,-1e10);
        dp[0] = 0;
        deque<int> q;
        int j = 0;
        F(i,1,n){
            while(a[j].fi + d <= a[i].fi){
                while(q.size() && dp[q.back()] <= dp[j]) q.pop_back();
                q.pb(j);
                j ++;
            }
            while(q.size() && a[q.front()].fi + u < a[i].fi) q.pop_front();
            if(q.size())dp[i] = dp[q.front()] + a[i].se;
            if(dp[i] >= k) return true;
        }
        return false;
    };
    while(l < r){
        int mid = (l + r) >> 1;
        if(check(mid))r = mid;
        else l = mid + 1;
    }
    if(l == k + 1) cout << "-1" << endl;
    else cout << l << endl;
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