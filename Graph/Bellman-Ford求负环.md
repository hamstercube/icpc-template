Bellman-Ford判负环

```cpp
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll i, j, n, m;
vector<pair<pair<ll, ll>, ll>> road;
ll d[2010];

bool b_f(){
	bool flag = 0;
	for(ll i = 0; i < road.size(); i++){
		auto [x, xt] = road[i].first;
		auto val = road[i].second;
		if(d[x]+val < d[xt]){
			d[xt] = d[x]+val;
			flag = 1;
		}
	}
	return flag;
}

void solve(){
	road.clear();
	memset(d, 0x3f3f3f, sizeof d);
	cin >> n >> m;
	for(ll i = 0; i < m; i++){
		ll t1, t2, t3;
		cin >> t1 >> t2 >> t3; 
		road.push_back({{t1, t2}, t3});
		if(t3 >= 0) road.push_back({{t2, t1}, t3});
	}
	ll cot = 0;
	d[1] = 0;
	while(cot < n){
		if(b_f()) cot++;
		else break;
	}
	//cout << cot << endl;
	if(cot == n){
		cout << "YES" << endl;
	}
	else{
		cout << "NO" << endl;
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	ll T;
	cin >> T;
	while(T--) solve();
	return 0;
}
```