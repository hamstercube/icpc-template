

// https://qoj.ac/contest/3590/problem/17783
//单向图！！！

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
using ai3 = array<int,3>;

const double PI = acos(-1);

void init(){
    ;
}

void solve(){
    int n,m,k;
    cin >> n >> m >> k;
    vector<vector<PII>> a(n + 10);
    for(int i = 1; i <= m; i ++){
        int u,v,w;
        cin >> u >> v >> w;
        a[u].pb({v,w});
    }
    vevei d1(n + 10, vei(k + 10,1e18));
    vevei d2(n + 10, vei(k + 10,1e18));
    vevei vis1(n + 10, vei(k + 10));
    vevei vis2(n + 10, vei(k + 10));
    auto dijk = [&]() -> void{
        priority_queue<ai3, vector<ai3>, greater<ai3>> q;
        q.push({0,1,0});
        d1[1][0] = 0;
        while(!q.empty()){
            auto [dist, idx, cen] = q.top();
            q.pop();
            if(vis1[idx][cen]) continue;
            vis1[idx][cen] = 1;
            for(auto it : a[idx]){
                if(d1[it.fi][cen] > dist + it.se){
                    d1[it.fi][cen] = dist + it.se;
                    q.push({dist + it.se, it.fi, cen});
                }
                if(cen < k && d1[it.fi][cen + 1] > dist){
                    d1[it.fi][cen + 1] = dist;
                    q.push({dist, it.fi, cen + 1});
                }
            }
        }
        q.push({0,n,0});
        d2[n][0] = 0;
        while(!q.empty()){
            auto [dist, idx, cen] = q.top();
            q.pop();
            if(vis2[idx][cen]) continue;
            vis2[idx][cen] = 1;
            for(auto it : a[idx]){
                if(d2[it.fi][cen] > dist + it.se){
                    d2[it.fi][cen] = dist + it.se;
                    q.push({dist + it.se, it.fi, cen});
                }
                if(cen < k && d2[it.fi][cen + 1] > dist){
                    d2[it.fi][cen + 1] = dist;
                    q.push({dist, it.fi, cen + 1});
                }
            }
        }
        int ans = 1e18;
        for(int i = 1; i <= n; i ++){
            for(int j = 1; j <= k; j ++){
                cmin(d1[i][j],d1[i][j - 1]);
                cmin(d2[i][j],d2[i][j - 1]);
            }
        }
        for(int i = 1; i <= n; i ++){
            for(int j = 0; j <= k; j ++){
                cmin(ans, d1[i][j] + d2[i][k - j]);
            }
        }
        if(ans > 1e17) ans = -1;
        cout << ans << endl;
    };
    dijk();
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