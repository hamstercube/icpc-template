集合元素可以相加， 判断mex

```cpp
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll i, j, n, m;

void solve(){
    cin >> n;
    multiset<ll> s, ss;
    for(ll i = 0; i < n; i++){
        ll t;
        cin >> t;
        s.insert(t);
    }
    ll mex = 0, used = 0;
    for(auto it : s){
        if(it <= mex+1) mex += it;
        else break;
    }
    ll sum = 0;
    while(sum < mex){
        auto p = prev(s.upper_bound(mex-sum));
        sum += *p;
        s.erase(p);
        used++;
    }
    cout << n-used << endl;
}

int main(){
    ll T;
    cin >> T;
    while(T--) solve();
    return 0;
}
```