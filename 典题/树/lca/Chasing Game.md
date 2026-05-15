
```cpp
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

ll i, j, n, m;
vector<ll> road[200100];
ll fc[200100][25], dep[200100];

void dfs(ll x, ll fa){
	dep[x] = dep[fa]+1, fc[x][0] = fa;
	for(ll i = 1; i <= 20; i++){
		fc[x][i] = fc[fc[x][i-1]][i-1];
	}
	for(auto xt : road[x]){
		if(xt == fa) continue;
		dfs(xt, x);
	}
}

ll lca(ll a, ll b){
	if(dep[a] < dep[b]) swap(a, b);
	for(ll i = 20; i >= 0; i--){
		if(dep[fc[a][i]] >= dep[b]) a = fc[a][i];
	}
	if(a == b) return a;
	for(ll i = 20; i >= 0; i--){
		if(fc[a][i] != fc[b][i]){
			a = fc[a][i], b = fc[b][i];
		}
	}
	return fc[a][0];
}

ll g_dis(ll x, ll y){
    ll lc = lca(x, y);
    return dep[x]-dep[lc]+dep[y]-dep[lc];
}

ll g_t(ll x, ll d){
    ll dk = dep[x]-d;
    for(ll i = 20; i >= 0; i--){
		if(dep[fc[x][i]] >= dk) x = fc[x][i];
	}
    return x;
}

void solve(){
    cin >> n >> m;
    for(ll i = 1; i < n; i++){
        ll x, y;
        cin >> x >> y;
        road[x].push_back(y);
        road[y].push_back(x);
    }
    dfs(1, 0);
    while(m--){
        ll s, t, s0;
        cin >> s >> t >> s0;
        ll d1 = g_dis(s, t), d2 = g_dis(s0, t);
        if(d2 > d1){
            cout << d2  << " " << t << endl;
        } else{
            ll d = g_dis(s, s0);
            ll t0;
            if(dep[s] > dep[s0]) t0 = g_t(s, (d+1)/2);
            else t0 = g_t(s0, d-(d+1)/2);
            cout << (d+1)/2 << " " << t0 << endl;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    ll T = 1;
    while(T--) solve();
    return 0;
}
```