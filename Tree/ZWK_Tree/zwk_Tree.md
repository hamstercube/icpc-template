```cpp
//建树时记录叶子节点深度 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e6; 
ll  P = 1, DEP = 0, tr[N+10], lz[N+10], n, m;
ll v[N+10];
ll mod;

void build(){
  	for(P = 1, DEP = 0; P <= n; P<<=1, DEP++);
  	for(ll i = 1; i <= n; i++) tr[i+P] = v[i];
  	for(ll i = (P+n)>>1; i; i--) {
        tr[i] = tr[i<<1]+tr[i<<1|1]; //合并左右子树的规则 
    }
}

void push_down(ll now, ll siz){ //push_dwon( 链上节点 , 当前子树大小（不是孩子的，孩子的要/2） )
    if(lz[now] == 0) return ;
    ll k = lz[now];
	ll lson = now<<1, rson = now<<1|1;
    ll s_siz = siz/2; // 孩子节点的大小
    
    tr[lson] += k*s_siz;
    tr[rson] += k*s_siz;

    lz[lson] += k, lz[rson] += k; // lz记得得看情况更改！
	lz[now] = 0;
}

void push_up(ll l){
    for( ; l; l>>=1) {
        tr[l] = tr[l<<1]+tr[l<<1|1];
    }
}

void update(ll l, ll r, ll k){
  	l=P+l-1; r=P+r+1;
  	//先下放标记 
  	for(ll i = DEP; i; i--) push_down(l>>i, 1<<i), push_down(r>>i, 1<<i); 
  	ll siz = 1;
  	for(; l^1^r; ){
  		if(~l&1){
            tr[l^1] += k*siz, lz[l^1] += k;
        }//正常更新
  		if(r&1){
            tr[r^1] += k*siz, lz[r^1] += k;
        }
  		l>>=1; r>>=1; siz<<=1;
        
  		tr[l] = tr[l<<1]+tr[l<<1|1];//由于标记已下放，所以维护时不再考虑累加标记 
        tr[r] = tr[r<<1]+tr[r<<1|1]; 
  	}
    push_up(l>>1);//上传至根节点 
}
  
ll query(ll l,ll r){
  	l = l+P-1, r = r+P+1;
  	for(ll i = DEP; i ; i--) push_down(l>>i, 1<<i), push_down(r>>i, 1<<i); // 下传标记 
  	ll res = 0;
  	for( ; l^1^r;){
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

// int main(){
// 	cin >> n >> m;
// 	for(ll i = 1; i <= n; i++){
// 		cin >> v[i];
// 	}
// 	build();
// 	while(m--){
// 		ll op, l, r, k;
// 		cin >> op;
// 		if(op == 1){
// 			cin >> l >> r >> k;
// 			update(l, r, k);
// 		}
// 		else{
// 			cin >> l >> r;
// 			cout << query(l, r) << endl;
// 		}
// 	}
// 	return 0;
// }

```