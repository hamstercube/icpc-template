交互题模板

```cpp
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;

ll i, j, n, m, p, q;
ll v[200100];

void solve(){
    cin >> n;
    ll lt, rt, mt;
    ll l0 = 1, r0 = 2*n+1;
    auto check0 = [&](ll mid) -> bool{
        cout << "? " <<  mid << " ";
        for(ll i = 1; i <= mid; i++){
            cout << i << " ";
        }
        cout << endl;
        cout.flush();
        ll res;
        cin >> res;
        return (mid-res)%2;
    };
    
    while(l0 < r0){
        ll mid = l0+r0>>1;
        if(check0(mid)) r0 = mid;
        else l0 = mid+1; 
    }
    rt = r0;
    ll l1 = 1, r1 = 2*n+1;
    auto check1 = [&](ll mid) -> bool{
        cout << "? " << mid << " ";
        for(ll i = 2*n+1-mid+1; i <= 2*n+1; i++){
            cout << i << " ";
        }
        cout << endl;
        cout.flush();
        ll res;
        cin >> res;
        return (mid-res)%2;
    };
    while(l1 < r1){
        ll mid = l1+r1>>1;
        if(check1(mid)) r1 = mid;
        else l1 = mid+1; 
    }
    lt = 2*n+1-r1+1;
    ll l2 = 1, r2 = rt-lt-1;
    auto check2 = [&](ll mid) -> bool{
        cout << "? " << mid+2 << " ";
        cout << lt << " " << rt << " ";
        for(ll i = lt+1; i <= lt+mid; i++){
            cout << i << " ";
        }
        cout << endl;
        cout.flush();
        ll res;
        cin >> res;
        return (mid+2-res)%2;
    };
    while(l2 < r2){
        ll mid = l2+r2>>1;
        if(check2(mid)) r2 = mid;
        else l2 = mid+1; 
    }
    mt = lt+r2;
    cout << "! " << lt << " " << rt << " " << mt << endl;
    cout.flush();
} 

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    ll T = 1;
    cin >> T;
    while (T--){
        solve(); 
    }
    return 0;
}
```