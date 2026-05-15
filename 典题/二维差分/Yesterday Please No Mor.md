Yesterday Please No Mor
二维差分

```cpp
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i, j, n, m, k;
string s;

void solve(){
	cin >> n >> m >> k;
	cin >> s;
	ll ans = 0;
	vector<vector<ll>> mp(n+5, vector<ll>(m+5, 0));
	vector<vector<bool>> vis(n+5, vector<bool>(m+5, 0));
	int l = 1, r = m, u = 1, d = n;
	int lt = 1, rt = m, ut = 1, dt = n;
	for(i = 0; i < s.size(); i++){
		if(s[i] == 'U'){
			if(ut == 1) u++;
			ut = max(1, ut-1);
			dt = max(1, dt-1);
		}
		else if(s[i] == 'D'){
			if(dt == n) d--;
			dt = min(n, dt+1);
			ut = min(n, ut+1);
		}
		else if(s[i] == 'L'){
			if(lt == 1) l++;
			lt = max(1, lt-1);
			rt = max(1, rt-1);
		}
		else if(s[i] == 'R'){
			if(rt == m) r--;
			lt = min(m, lt+1);
			rt = min(m, rt+1);
		}
	}
	bool flag = 0;
	if(u > d || l > r){
		flag = 1;
	}
   ll xt = u, yt = l, lenx = d-u, leny = r-l, sum = (d-u+1)*(r-l+1);
   // cout << xt << " " << yt << " " << lenx  << " " << leny << endl;
    if(!flag){
		for(i = -1; i < (ll)s.size(); i++){
			auto add = [&](ll x1, ll y1){
				if(vis[x1][y1]) return;
				vis[x1][y1] = 1;
				ll x2 = x1+lenx, y2 = y1+leny;
				mp[x1][y1]++, mp[x2+1][y2+1]++;
				mp[x1][y2+1]--, mp[x2+1][y1]--; 
			};
			if(i == -1){
				add(xt, yt);
				continue;
			}
			if(s[i] == 'U') xt--;
			else if(s[i] == 'D') xt++;
			else if(s[i] == 'L') yt--;
			else if(s[i] == 'R') yt++;
			add(xt, yt);
		}
	}
	else sum = 0;
	for(ll i = 1; i <= n; i++){
		for(ll j = 1; j <= m; j++){
			mp[i][j] = mp[i][j]+mp[i-1][j]+mp[i][j-1]-mp[i-1][j-1];
			ll t = mp[i][j];
			if(sum-t == k) ans++;
		}
	}
	cout << ans << endl;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	ll T;
	cin >> T;
	while(T--){
		solve();
	}
	return 0;
}
```