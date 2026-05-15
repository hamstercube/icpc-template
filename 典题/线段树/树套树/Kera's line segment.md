处理单点更新二维线段树问题

```cpp
//建树时记录叶子节点深度 
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

const int N = 4096;
int  P = 4096, DEP = 0, tr[2][9001][9001], n, m;

void push_up(int f, int l){
    for(; l; l >>= 1){
        tr[0][f][l] = max(tr[0][f][l<<1], tr[0][f][l<<1|1]);
		tr[1][f][l] = min(tr[1][f][l<<1], tr[1][f][l<<1|1]);
    }
}

void update1(int f, int l, int r, int k){
    l=P+l-1; r=P+r+1;
    for( ; l^1^r;){
  		if(~l&1){
           tr[0][f][l^1] = max(tr[0][f][l^1], k);
           tr[1][f][l^1] = min(tr[1][f][l^1], k);
        }
  		if(r&1){
           tr[0][f][r^1] = max(tr[0][f][r^1], k);
           tr[1][f][r^1] = min(tr[1][f][r^1], k);
        }
  		l >>= 1; r >>= 1;
        tr[0][f][l] = max(tr[0][f][l<<1], tr[0][f][l<<1|1]);
        tr[1][f][l] = min(tr[1][f][l<<1], tr[1][f][l<<1|1]);
        tr[0][f][r] = max(tr[0][f][r<<1], tr[0][f][r<<1|1]);
        tr[1][f][r] = min(tr[1][f][r<<1], tr[1][f][r<<1|1]);
  	}
//     cout << tr[0][f][l] << " " << tr[1][f][r] << endl;
    push_up(f, l);
}

void update(int l, int r, int k){
  	for(l += P; l; l >>= 1){
        update1(l, r, r, k);
    }
}

array<int, 2> query1(int f, int l, int r){
  	l = l+P-1, r = r+P+1;
  	int resb = 0, ress = 2e9;
  	for( ; l^1^r;){
  		if(~l&1){
           resb = max(resb, tr[0][f][l^1]);
           ress = min(ress, tr[1][f][l^1]);
        }
  		if(r&1){
           resb = max(resb, tr[0][f][r^1]);
           ress = min(ress, tr[1][f][r^1]);
        }
  		l >>= 1; r >>= 1;
  	}
  	return {resb, ress};
}

int query(int l, int r, int k){
  	l = l+P-1, r = r+P+1;
  	int resb = 0, ress = 2e9;
  	for( ; l^1^r;){
  		if(~l&1){
            array<int, 2> a = query1(l^1, 1, k);
            resb = max(resb, a[0]);
            ress = min(ress, a[1]);
        }
  		if(r&1){
            array<int, 2> a = query1(r^1, 1, k);
            resb = max(resb, a[0]);
            ress = min(ress, a[1]);
        }
  		l >>= 1; r >>= 1;
  	}
//     cout << resb << " " << ress << endl;
  	return max(resb-ress, 0);
}
                                      
int main(){
    memset(tr[1], 0x3f3f3f, sizeof tr[1]);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		int l, r, val;
        cin >> l >> r >> val;
		update(l, r, val);
	}
    int ans = 0;
	while(m--){
		int op, l, r, k;
		cin >> op;
		if(op == 1){
			cin >> l >> r >> k;
            l ^= ans, r ^= ans;
			update(l, r, k);
		}
		else{
			cin >> l >> r;
            l ^= ans, r ^= ans;
            ans = query(l, r, r);
			cout << ans << endl;
		}
	}
	return 0;
}
```
