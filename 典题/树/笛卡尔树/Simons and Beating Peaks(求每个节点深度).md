Simons and Beating Peaks(求笛卡尔树每个节点深度)

当你遇到一个排列且最大值有着关键作用如可以区分左右两个区间
那可以往笛卡尔树的方向想想

```cpp
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll i, j, n, m;
ll v[500100], stk[500100];

void solve(){
	cin >> n;
	vector<ll> del(n+1), del1(n+1);
	ll top;
	for(ll i = 1; i <= n; i++){
		cin >> v[i];
	}
	top = 0;
	for(ll i = 1; i <= n; i++){
		while(top && v[stk[top]]<v[i]){
			top--;
		}
		stk[++top] = i;
		del[i] += i-top;
	}
	for(ll i = 1; i <= n; i++){
		cout << del[i] << " ";
	}
	cout << endl;
	top = 0;
	for(ll i = n; i >= 1; i--){
		while(top && v[stk[top]]<v[i]){
			top--;
		}
		stk[++top] = i;
		del1[i] += n-i+1-top; 
 	}
 	for(ll i = 1; i <= n; i++){
		cout << del1[i] << " ";
	}
	cout << endl;
 	ll ans = 1e10;
 	for(ll i = 1; i <= n; i++){
 		ans = min(ans, del[i]+del1[i]);
	}
	cout << ans << endl;
}

int main(){
	ll T;
	cin >> T;
	while(T--) solve();
	return 0;
} 
```