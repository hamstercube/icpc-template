lca+前缀线性基

```cpp
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;

ll i, j, n, m, t1, t2, q;
ll X[20100][65], pos[20100][65];
ll fa[20100][20], dep[20100];
ll cot[20100], v[65];
vector<ll> road[20100];

void update(ll x, ll sz, ll f){
    for(ll i = 60; i >= 0; i--){
        X[sz][i] = X[f][i]; 
        pos[sz][i] = pos[f][i];
    }
    ll p = dep[sz];
    for(ll i = 60; i >= 0; i--){
        ll t = x>>i;
        if(!t) continue;
        if(!X[sz][i]){
            X[sz][i] = x;
            pos[sz][i] = p;
            return ;
        }
        if(pos[sz][i] < p){
            swap(X[sz][i], x);
            swap(pos[sz][i], p);
        }
        x ^= X[sz][i];
    }
}

void update1(ll x){
    for(ll i = 60; i >= 0; i--){
        ll t = x>>i;
        if(!t) continue;
        if(!v[i]){
            v[i] = x;
            return;
        }
        x ^= v[i];
    }
}

void merge(ll x, ll z){
    for(ll i = 60; i >= 0; i--){
        if(X[x][i] && pos[x][i] >= dep[z]){
            update1(X[x][i]);
        }
    }
}

void dfs(ll x, ll f){
    dep[x] = dep[f]+1;
    fa[x][0] = f;
    update(cot[x], x, f);
    for(ll i = 1; i <= 15; i++){
        fa[x][i] = fa[fa[x][i-1]][i-1];
    }
    for(auto xt: road[x]){
        if(xt == f) continue;
        dfs(xt, x);
    }
}

ll lca(ll a, ll b){
    if(dep[a] < dep[b]) swap(a, b);
    for(ll i = 15; i >= 0; i--){
        if(dep[fa[a][i]] >= dep[b]) a = fa[a][i];
    }
    if(a == b) return a;
    for(ll i = 15; i >= 0; i--){
        if(fa[a][i] != fa[b][i]){
            a = fa[a][i];
            b = fa[b][i];
        }
    }
    return fa[a][0];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    for(i = 1; i <= n; i++){
        cin >> cot[i];
    }
    for(i = 0; i < n-1; i++){
        cin >> t1 >> t2;
        road[t1].push_back(t2);
        road[t2].push_back(t1);
    }
    dfs(1, 0);
    ll st, to;
    while(q--){
        memset(v, 0, sizeof v);
        cin >> st >> to;
        ll lc = lca(st,to);
       // cout << lc << endl;
        ll ans = 0;
        merge(st, lc);
        merge(to, lc);
        for(i = 60; i >= 0; i--){
            ans = max(ans, ans^v[i]);
        }
        cout << ans << endl;
    }
    return 0;
}
```