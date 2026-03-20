#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;

void solve(){
    cin >> n;
    vector<array<ll, 2>> v;
    ll d[410][410] = {0};
    deque<array<ll, 3>> de; // {val, x, y}

    for(ll i = 1; i <= n; i++){
        ll x, y;
        cin >> x >> y;            // x轴与y轴
        if(d[x][y]) continue;   // 去重
        v.push_back({x, y});
        de.push_back({1, x, y});
        d[x][y] = 1;
    }

    ll upm = 200, dom = -200;     //根据题意设置上界与下界防止越界
    auto check = [&](ll x, ll y) -> bool{
        if(x > upm || y > upm || x < dom || y < dom) return 0;
        return 1;
    };
    auto bfs = [&](){
        while(de.size()){
            auto [val, x, y] = de.front();
            de.pop_front();
            for(ll i = 0; i < v.size(); i++){
                ll xt = x+v[i][0], yt = y+v[i][1];
                if(check(xt, yt) == 0 || d[x][y]) continue;
                d[x][y] = val+1;
                de.push_back({val+1, xt, yt});
            }
        }
    };
    bfs();
    if(d[0][0]) cout << d[0][0] << endl;
    else cout << -1 << endl;
}