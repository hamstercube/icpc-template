hard math
数位dp

```md
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll i, j, n, m;
ll mod = 1e9+7;

ll k[2];
string s[2];
ll dp[200100][20][2], A;
ll ha[20];

ll dfs(ll flag, ll p, ll pre, ll len, ll free){
	if(pre > A) return 0;
	if(len == 0){
		if(pre == A) return 1;
		return 0;
	}
	if(dp[len][pre][free] != -1) return dp[len][pre][free];
	ll top = 9;
	if(!free) top = s[flag][p]-'0';
	ll res = 0;
	for(ll i = 0; i <= top; i++){
		if(pre == 0 && i == 0) res += dfs(flag, p+1, 0, len-1, 1), res %= mod;
		else{
			ha[i]++;
			ll add = 0;
			if(ha[i] == 1) add++;
			res += dfs(flag, p+1, pre+add, len-1, free||!free&&i!=top);
			res %= mod;
			ha[i]--;
		}
	}
	return dp[len][pre][free] = res;
}

ll check(string s){
	bool vis[10] = {0};
	ll cot = 0;
	for(ll i = 0; i < n; i++){
		ll t = s[i]-'0';
		if(!vis[t]) cot++;
		vis[t] = 1;
	}
	if(cot == A) return 1;
	return 0;
}

int main(){
	ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
	cin >> n;
	cin >> s[0] >> s[1];
	cin >> A;
	for(ll i = 0; i < 2; i++){
		memset(&dp, -1, sizeof dp);
		k[i] = dfs(i, 0, 0, n, 0);
	}
	ll ans = 0;
	ans = check(s[0]);
	//cout << k[0] << " " << k[1] << endl;
	ans += k[1]-k[0]+mod;
	ans %= mod;
	cout << ans << endl;
	return 0;
}

```