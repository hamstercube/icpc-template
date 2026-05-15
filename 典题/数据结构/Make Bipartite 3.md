带权并查集

```cpp
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll i, j, n, m;
ll fa[1000100], cot[1000100], num[1000100];
ll sz = 0;

// ^1= 兄弟， /2 = 集合 
// (sum-ca)/2 最小值

ll Find(ll x){
	if(fa[x] == x) return x;
	return fa[x] = Find(fa[x]);
} 

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for(ll i = 0; i <= 2*n; i++){
        fa[i] = i;
        num[i] = -1;
    }
    bool f = 1;
    ll sum = 0, ca = 0;
    
    auto build = [&](ll x, ll y){
        num[x] = sz, num[y] = sz^1;
        cot[sz]++, cot[sz^1]++;
        sum += 2, sz += 2;
    };
    auto add = [&](ll x, ll y){
        ll fx = Find(num[x]);
        num[y] = fx^1;
        ca -= abs(cot[fx]-cot[fx^1]);
        sum++, cot[fx^1]++;
        ca += abs(cot[fx]-cot[fx^1]);
    };
    auto merge = [&](ll x, ll y) -> bool{
        ll fx = Find(num[x]), fy = Find(num[y]);
        if(fx/2 == fy/2){
            if((fx&1) == (fy&1)) return 0;
            return 1;
        } 
        ca -= abs(cot[fy]-cot[fy^1])+abs(cot[fx]-cot[fx^1]);
        cot[fx] += cot[fy^1], cot[fx^1] += cot[fy];
        fa[fy] = fx^1, fa[fy^1] = fx;
        ca += abs(cot[fx]-cot[fx^1]);
        return 1;
    };
    
    for(ll i = 1; i <= m; i++){
        ll x, y;
        cin >> x >> y;
        if(f == 0){
            cout << -1 << endl;
            continue;
        } 

        if(num[x] != -1 && num[y] != -1){
            if(merge(x, y) == 0){
                cout << -1 << endl;
                f = 0;
                continue;
            }
        }else if(num[x] != -1){
            add(x, y);
        } else if(num[y] != -1){
            add(y, x);
        } else{
            build(x, y);
        }
        cout << (sum-ca)/2 << endl;
    }
    return 0;
}
```