set区间分割

```cpp
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll i, j, n, m, x;
ll N = 3e9, INF = 1e18;

void solve(){
    cin >> n >> x;
    set<array<ll, 3>> st;
    st.insert({0, INF, INF});
    deque<array<ll, 3>> del, add;
    for(ll i = 1; i <= n; i++){
        ll l, r, v;
        cin >> l >> r >> v;
        ll be = max((x-r+v-1)/v, 0ll), en = (x-l)/v;
        if(be > en) continue;
        ll len = r-l;
        auto it = --st.upper_bound({be, INF+1, 0});
        array<ll, 3> ad = {-1, -1, len};
        while(it != st.end() && (*it)[0] <= en){
            auto lt = *it;
            if(lt[2] > len){
                if(ad[0] == -1) ad[0] = max(be, lt[0]);
                ad[1] = min(en, lt[1]);
                del.push_back(lt);
                if(lt[0] < be) add.push_back({lt[0], be-1, lt[2]});
                if(lt[1] > en) add.push_back({en+1, lt[1], lt[2]});
            } else if(ad[0] != -1){
                add.push_back({ad});
                ad = {-1, -1, len};
            }
            it++;
        }
        if(ad[0] != -1) add.push_back(ad);
        while(del.size()){
            st.erase(del.front());
            del.pop_front();
        }
        while(add.size()){
            st.insert(add.front());
            add.pop_front();
        }
    }
    ll ans = 0;
    for(auto [x, y, z] : st){
    	if(z != INF) ans = max(ans, z);
	}
    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    ll T = 1;
    while(T--) solve();
    return 0;
}
```