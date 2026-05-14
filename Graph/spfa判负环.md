SPFA判负环

```cpp
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll i, j, n, m;
vector<pair<ll, ll>> road[2010];

bool spfa(){
	vector<bool> ent(n+1, 0);
	vector<ll> d(n+1, 1e10), cot(n+1, 0);
	queue<ll> q;
	q.push(1);
	d[1] = 0, ent[1] = 1;
	while(q.size()){
		ll x = q.front();
		q.pop();
		ent[x] = 0, cot[x]++;
		if(cot[x] == n) return 1;
		for(auto [xt, val] : road[x]){
			ll t = d[x]+val;
			if(d[xt] > t){
				d[xt] = t;
				if(!ent[xt]){
					ent[xt] = 1;
					q.push(xt);
				}
			}
		}
	}
	return 0;
}

void solve(){
	cin >> n >> m;
	for(ll i = 1; i <= n; i++) road[i].clear(); 
	for(ll i = 0; i < m; i++){
		ll t1, t2, t3;
		cin >> t1 >> t2 >> t3;
		road[t1].push_back({t2, t3});
		if(t3 >= 0) road[t2].push_back({t1, t3});
	}
	if(spfa()){
		cout << "YES" << endl;
	}
	else{
		cout << "NO" << endl;
	}
}

int main(){
	ll T;
	cin >> T;
	while(T--) solve();
	return 0;
} 
```