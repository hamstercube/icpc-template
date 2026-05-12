```cpp
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll i, j, n, m, S, T;
ll dep[1210], cur[1210];
struct edge{
	ll xt, val, f;
};
vector<edge> road[1210];

bool bfs(){
	memset(dep, -1, sizeof dep);
	queue<ll> q;
	q.push(S);
	dep[S] = 0;
	while(q.size()){
		ll x = q.front();
		q.pop();
		for(auto [xt, val, f] : road[x]){
			if(dep[xt] == -1 && val){
				dep[xt] = dep[x]+1;
				q.push(xt);
			}
		}
	}
	
	return dep[T] != -1;
}

ll dfs(ll x, ll fm){
	if(x == T) return fm;
	for(ll i = cur[x]; i < road[x].size(); i++){
		auto [xt, val, f] = road[x][i];
		cur[x] = i;
		if(dep[xt] == dep[x]+1 && val){
			ll t = dfs(xt, min(fm, val));
			if(t){
				road[x][i].val -= t;
				road[xt][f].val += t;
				return t;
			}
			else dep[xt] = -1;
		}
	}
	return 0;
}

ll Dinic(){
	ll flow = 0, add;
	while(bfs()){
		memset(cur, 0, sizeof cur);
		while(add = dfs(S, 1e18)) flow += add;
	}
	return flow;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	cin >> S >>  T;
	for(ll i = 0; i < m; i++){
		ll t1, t2, t3;
		cin >> t1 >> t2 >> t3;
		auto add_e = [&](ll u, ll v, ll val){
			ll s1 = road[u].size(), s2 = road[v].size();
			road[u].push_back({v, val, s2});
			road[v].push_back({u, 0, s1}); //注意反向边权值初始化为0 
		};
		add_e(t1, t2, t3);
	}
	cout << Dinic() << endl;
	return 0;
}
```