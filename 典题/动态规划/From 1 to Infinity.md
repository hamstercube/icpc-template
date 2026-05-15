
求一个数1-n每个数的逐位数字相加总和
本题是1-n每位数前后相接，求k位的前n项和
123456789101112···

```cpp
#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

ll i, j, n, m;

ll quick(ll x, ll k){
    ll res = 1;
    while(k){
        if(k&1) res = res*x;
        x = x*x;
        k >>= 1;
    }
    return res;
}

void solve(){
    cin >> n;
    auto calc = [&](ll x) -> array<ll, 2> {
        ll i, j, pr = 0, k;
        for(i = 1, j = 9;  ; i++, j *= 10){
            if(j*i >= x) break;
            x -= j*i;
            pr += j;
            // cout << x << endl;
        }
        pr += (x+i-1)/i, k = x%i;
        array<ll, 2> a{pr, k};
        return a;
    };
    auto [pr, k] = calc(n);
    //  cout << pr << " " << k << endl;
    ll ans = 0;
    string s = to_string(pr);
    s = " "+s;
    for(ll i = 1; i <= k; i++){
        ans += s[i]-'0';
    }
    if(k) pr--;
    s = to_string(pr);
    s = " "+s;
    ll sum = 0;
    auto g_k  = [&](ll p)-> ll{
        if(p+1 == s.size()) return 1;
        string ss(s.begin()+1+p, s.end());
        return stoll(ss)+1;
    };
    ll p10 = quick(10, s.size()-2);
    for(ll i = 1, j = s.size()-2; i < s.size(); i++, j--, p10/=10){
        ll t = s[i]-'0';
        ans += (t-1)*t/2*p10+t*45*j*p10/10;
        ans += t*g_k(i);
        // cout << g_k(i) << endl;
        // cout << i << " " << j << " " << p10 << " " << t << endl;
    }
    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    ll T;
    cin >> T;
    while(T--) solve();
    return 0;
}
```