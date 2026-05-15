换根dp

```cpp
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll i, j, n, m, k;
ll sm[400100][2], fm[400100], siz[400100];
vector<ll> road[400100];
bool vis[400100] = {0};

void dfs(ll x, ll fa){
	siz[x] = 1;
	for(auto xt : road[x]){
		if(xt == fa) continue;
		dfs(xt, x);
		siz[x] += siz[xt];
		for(ll i = 0; i < 3; i++){
			ll k1;
			if(i > 0) k1 = sm[xt][i-1];
			else k1 = siz[xt];
			if(k1 > k) continue;
			if(sm[x][0] < k1){
				sm[x][1] = sm[x][0];
				sm[x][0] = k1;
				fm[x] = xt;
				break;
			}
			else if(sm[x][1] < k1){
				sm[x][1] = k1;
				break;
			}
		}
	}
}

void dfs1(ll x, ll fa){
	ll cot = siz[1] - siz[x];
	if(cot > k){
		ll t;
		if(fm[fa] != x) t = sm[fa][0];
		else t = sm[fa][1];
		if(cot - t > k) vis[x] = 1;
	}
	else{
		for(auto xt : road[x]){
			if(xt == fa) continue;
			if(siz[xt] > k){
				if(siz[xt] - sm[xt][0] > k) vis[x] = 1;
				break;
			}
		}
	}
	for(ll i = 0; i < 3; i++){
		if(i == 1 && fm[fa] == x) continue;
		ll k1;
		if(i > 0) k1 = sm[fa][i-1];
		else k1 = cot;
	//	cout << x << " " << i << " " << k1 << endl;
		if(k1 > k) continue;
		if(sm[x][0] < k1){
			sm[x][1] = sm[x][0];
			sm[x][0] = k1;
			fm[x] = fa;
			break;
		}
		else if(sm[x][1] < k1){
			sm[x][1] = k1;
			break;
		}
	}
	for(auto xt : road[x]){
		if(xt == fa) continue;
		dfs1(xt, x);
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n;
	k = n/2;
	for(ll i = 1; i < n; i++){
		ll t1, t2;
		cin >> t1 >> t2;
		road[t1].push_back(t2);
		road[t2].push_back(t1);
	}
	dfs(1, 0);
	dfs1(1, 0);
	for(ll i = 1; i <= n; i++){
		if(!vis[i]) cout << 1 << " ";
		else cout << 0 << " ";
	//	cout << sm[i][0] << " " << sm[i][1] << " " << fm[i] << endl;
	}
	return 0;
} 

```