有理数取余(扩展gcd取余)

```cpp
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll i, j, n, m;
string s[2];
ll mod = 19260817;
ll cot[2];

ll ex_gcd(ll a, ll b, ll &x, ll &y){
	if(b == 0){
		x = 1, y = 0;
		return a;
	}
	ll res = ex_gcd(b ,a%b, y, x);
	y = y-a/b*x;
	return res;
}

int main(){
	ll x, y;
	cin >> s[0] >> s[1];
	for(ll i = 0; i < 2; i++){
		reverse(s[i].begin(), s[i].end());
		for(ll j = 0, h = 1; s[i][j]; j++, h = h*10%mod){
			ll t = s[i][j]-'0';
			cot[i] = (cot[i]+t*h%mod)%mod;
		}
	}
	ex_gcd(cot[1], mod, x, y);
	cout << cot[0]*((x+mod)%mod)%mod;
	return 0;
}
```