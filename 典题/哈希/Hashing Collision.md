双哈希

```cpp
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

ll i, j, n ,m, p;
ll B = 13331;
ll mod = 10000000000000061;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0); 
    cin >> n >> p >> m;
    vector<int> a(n + 10);
    vector<ll> b(1);
    vector<ll> c(1);
    for(int i = 1; i <= n; i ++) cin >> a[i];
    ll ans = 0;
    for(int i = 1; i <= n; i ++){
        ll k = 0, pp = 1;
        ll kk = 0;
        for(int j = i; j <= n; j ++){
            k = (k+pp*a[j]%m)%m;
            kk = (kk*B%mod+a[j])%mod;
            pp = pp*p%m;
            b.push_back(k);
            c.push_back(kk);
        }
    }
    sort(b.begin()+1, b.end());
    sort(c.begin()+1, c.end());
    for(int i = 1, j = 1; i < b.size(); i++){
    	 if(i != 1 && b[i] == b[i-1]){
            j++;
		 } else j = 1;
		 ans += 2*(j-1);
	}
	for(int i = 1, j = 1; i < c.size(); i++){
    	 if(i != 1 && c[i] == c[i-1]){
            j++;
		 } else j = 1;
		 ans -= 2*(j-1);
	}
    cout << ans << endl;
    return 0;
}
```