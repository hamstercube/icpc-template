#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll N = 3e6;
ll n, m, k;
deque<ll> de[1000100];
ll v[1000100];

ll  P = 1, DEP = 0, tr[N+10];
ll cnt[N+10];

void build(){
  	for(P = 1, DEP = 0; P <= n; P<<=1, DEP++);
}

void push_up(ll l, ll siz){
 	for( ; l; l>>=1, siz<<=1) {
 		if(cnt[l]) tr[l] = siz;
        else if(siz == 1) tr[l] = 0;
        else tr[l] = tr[l<<1]+tr[l<<1|1];
    }
} 

void update(ll l, ll r, ll k){
  	l=P+l-1; r=P+r+1;
  	ll siz = 1;
  	for(; l^1^r; ){
  		if(~l&1){
  			cnt[l^1] += k;
  			if(cnt[l^1]) tr[l^1] = siz;
            else if(siz == 1) tr[l^1] = 0;
            else tr[l^1] = tr[(l^1)<<1]+tr[(l^1)<<1|1]; 
        }
  		if(r&1){
            cnt[r^1] += k;
  			if(cnt[r^1]) tr[r^1] = siz;
            else if(siz == 1) tr[r^1] = 0;
            else tr[r^1] = tr[(r^1)<<1]+tr[(r^1)<<1|1]; 
        }
        
  		l >>= 1, r >>= 1, siz <<= 1;
  		
        if(cnt[l]) tr[l] = siz;
        else if(siz == 1) tr[l] = 0;
    	else tr[l] = tr[l<<1]+tr[l<<1|1]; 
        if(cnt[r]) tr[r] = siz;
        else if(siz == 1) tr[r] = 0;
        else tr[r] = tr[r<<1]+tr[r<<1|1]; 
  	}
    push_up(l>>1, siz<<1);
}
  
ll query(ll l, ll r){
  	l = l+P-1, r = r+P+1;
  	ll res = 0;
  	for( ; l^1^r; ){
  		if(~l&1){
            res += tr[l^1];
        }
  		if(r&1){
            res += tr[r^1];
        }
  		l >>= 1; r >>= 1;
  	}
  	return res;
}

vector<array<ll, 4>> link;

void solve(){
	cin >> n >> k;
	for(ll i = 1; i <= 1e6; i++) de[i].push_back(0);
	for(ll i = 1; i <= n; i++){
		cin >> v[i];
		de[v[i]].push_back(i);
	}
	for(ll i = 1; i <= 1e6; i++) de[i].push_back(n+1);
	build();
	for(ll i = 1; i <= 1e6; i++){
		if(de[i].size()-2 < k) continue;
		for(ll j = k; j < de[i].size()-1; j++){
			link.push_back({de[i][j], de[i][j-k]+1, de[i][j-k+1], 1});
			link.push_back({de[i][j+1], de[i][j-k]+1, de[i][j-k+1], -1});
		}
	}
	sort(link.begin(), link.end());
	ll ans = n*(n+1)/2;
	for(ll i = 1, lt = 0; i <= n; i++){
		while(lt < link.size() && link[lt][0] == i){
			auto [ti, l, r, d] = link[lt];
			update(l, r, d);
			lt++; 
		}
		ans -= query(1, n);
	}
	cout << ans << endl;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll T = 1;
	while(T--) solve();
	return 0;
}
