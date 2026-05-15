线性基记录路径

对于每个i,求选者a[i]或b[i],使得异或和为0

```cpp
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll i, j, n, m;
ll X[35], p[35];
ll a[200100], b[200100];
unsigned long long ha[35];

void solve(){
    memset(X, 0, sizeof X), memset(p, 0, sizeof p), memset(ha, 0, sizeof ha);
    cin >> n;
    ll A = 0, B = 0;
    for(ll i = 1; i <= n; i++) cin >> a[i], A^=a[i];
    for(ll i = 1; i <= n; i++) cin >> b[i], B^=b[i];
    if(A == 0){
        for(ll i = 1; i <= n; i++) cout << a[i] << " ";
        cout << endl;
        return ;
    }else if(B == 0){
        for(ll i = 1; i <= n; i++) cout << b[i] << " ";
        cout << endl;
        return ;
    }
    ll cot = 0;
    for(ll i = 1; i <= n; i++){
        ll k = a[i]^b[i];
        unsigned long long num = 1<<cot;
        for(ll j = 30; j >= 0; j--){
            ll t = (k>>j)&1;
            if(!t) continue;
            if(!X[j]){
                X[j] = k;
                ha[j] = num;
                p[cot] = i;
                cot++;
                break;
            }else{
                k ^= X[j];
                num ^= ha[j];
            }
        }
    }
    ll k = A;
    unsigned long long key = 0;
    for(ll i = 30; i >= 0; i--){
        ll t = (k>>i)&1;
        if(!t) continue;
        if(!X[i]){
            cout << -1 << endl;
            return ;
        }else{
            k ^= X[i];
            key ^= ha[i];
        }
    }
    for(ll i = 30; i >= 0; i--){
        ll t = (key>>i)&1;
        if(t) swap(a[p[i]], b[p[i]]);
    }
    for(ll i = 1; i <= n; i++) cout << a[i] << " ";
    cout << endl;
}

int main(){
    ll T;
    cin >> T;
    while(T--) solve();
    return 0;
}
```