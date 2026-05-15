二分求中位数的中位数

```cpp
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll i, j, n, m;
ll a[2010], v[2010];

int main(){
	cin >> n;
	for(ll i = 1; i <= n; i++) cin >> a[i];
	ll l = 1, r = 1e9;
	auto check = [&](ll mid) -> bool{
		for(ll i = 1; i <= n; i++){
			if(a[i] >= mid) v[i] = 1;
			else v[i] = 0;
		}
		vector<vector<ll>> b(n+1, vector<ll>(n+1, 0));
		for(ll i = 1; i <= n; i++){
			ll cot = 0;
			for(ll j = i; j <= n; j++){
				if(v[j] == 1) cot++;
				if(cot > (j-i+1)/2) b[i][j] = 1;
			}
		}
		for(ll i = 1; i <= n; i++){
			for(ll j = 1; j <= n; j++){
				b[i][j] = b[i-1][j]+b[i][j-1]-b[i-1][j-1]+b[i][j]; 
			}
		}
		ll sum = 0;
		for(ll i = 1; i <= n; i++){
			for(ll j = i; j <= n; j++){
				ll k = b[j][j]-b[j][i-1]-b[i-1][j]+b[i-1][i-1];
				if(k > (j-i+1+(j-i+1)*(j-i)/2)/2) sum++;
			}
		}
//		cout << sum << endl;
		if(sum > (n-1+1+(n-1+1)*(n-1)/2)/2) return true;
		return false;
	};
	while(l < r){
		ll mid = l+r+1>>1;
//		cout << mid << endl;
		if(check(mid)) l = mid;
		else r = mid-1;
	}
	cout << l;
	return 0;
} 
```