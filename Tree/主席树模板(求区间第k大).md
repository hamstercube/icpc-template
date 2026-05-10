```cpp
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll i, j, n, m, h, sz = 0, siz;
ll lc[3200100], rc[3200100], sum[3200100], rt[3200100];
ll a[100100], b[100100];
// ll c[100100]; 与原效果相反 

void build(ll &now, ll l, ll r){
	now = ++sz;
	if(l==r) return;
	ll mid = l+r>>1;
	build(lc[now], l, mid);
	build(rc[now], mid+1, r);
} 

ll update(ll now,ll l,ll r,ll mu){
	ll next= ++sz;
	lc[next] = lc[now], rc[next] = rc[now], sum[next] = sum[now]+1;
	if(l==r) return next;
	ll mid = l+r>>1;
	if(mid >= mu) lc[next] = update(lc[next], l, mid, mu);
	else rc[next] = update(rc[next], mid+1, r, mu);
	return next;
}

ll query(ll u,ll v,ll l,ll r,ll mu){
	ll x = sum[lc[v]]-sum[lc[u]], mid = l+r>>1;
	if(l == r) return l;
	if(mu <= x) return query(lc[u], lc[v], l, mid, mu);
	else return query(rc[u], rc[v], mid+1, r, mu-x);
}

int main(){
	cin >> n;
	for(i = 1; i <= n; i++){
		cin >> a[i];
		b[i] = a[i];
		c[i] = b[i];
	}
	sort(b+1, b+n+1); 
	siz = unique(b+1, b+n+1) - b - 1;  // 离散化 
	//sort(c+1, c+n+1);
	//unique(c+1, c+n+1);
	//sort(c+1, c+siz+1, greater<ll>());
	build(rt[0], 1, siz);
	for(i = 1; i <= n; i++){
		ll p = lower_bound(b+1, b+siz+1, a[i]) - b;
		rt[i] = update(rt[i-1], 1, siz, p);
	}
	cin >> m;
	while(m--){
		ll l, r, k;
		cin >> l >> r >> k;
		cout << b[query(rt[l-1], rt[r], 1, siz, k)] << endl; 
	//	cout << c[query(rt[l-1], rt[r], 1, siz, k)] << endl;
	}
	return 0;
}
```