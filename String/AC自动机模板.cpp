#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll i, j, n, m, sz = 0;
ll tree[1000100][26], cot[1000100];
ll ne[1000100];



void update(string &s){
	ll p = 0;
	for(ll i = 0; i < s.size(); i++){
		ll t = s[i]-'a';
		if(!tree[p][t]) tree[p][t] = ++sz;
		p = tree[p][t];
	}
	cot[p]++;
}

void build(){
	queue<ll> q;
	for(ll i = 0; i < 26; i++){
		if(tree[0][i]) q.push(tree[0][i]);
	}
	while(q.size()){
		ll u = q.front();
		q.pop();
		for(ll i = 0; i < 26; i++){
			ll v = tree[u][i];
			if(v) ne[v] = tree[ne[u]][i], q.push(v);
			else tree[u][i] = tree[ne[u]][i];
		}
	}
}

ll query(string s){
	ll res = 0;
	for(ll i = 0, k = 0; i < s.size(); i++){
		ll t = s[i]-'a';
		k = tree[k][t];
		for(ll j = k; j && ~cot[j]; j = ne[j]){
			res += cot[j], cot[j] = -1;
		}
	}
	return res;
}

void solve(){
	cin >> n;
	for(i = 0; i < n; i++){
		string s;
		cin >> s;
		update(s);
	}
	build();
	string s1;
	cin >> s1;
	cout << query(s1) << endl;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	ll T = 1;
	while(T--){
		solve();
	}
	return 0;
}
