//处理区间不同数个数

#include<bits/stdc++.h>
using namespace std;
typedef int ll;

ll i, j, n, m, k;
bool ans [100001];
ll v[100001];
ll cot = 0;
ll mp[1001000];

struct node{
	ll l;
	ll r;
	ll num;
} q[100001];


bool cmp(node a, node b){
	if(a.l/k != b.l/k) return a.l < b.l;
	return a.r < b.r;
}

int main(){
	scanf("%d %d", &n, &m);
	k = sqrtl(n);
	for(i = 1; i <= n; i++){
		scanf("%d", &v[i]);
	}
	for(i = 0; i < m; i++){
		ll l, r;
		scanf("%d %d", &l, &r);
		q[i] = {l, r, i};
	}
	sort(q, q+m, cmp);
	
	for(ll i = 0, lt = 1, rt = 0; i < m; i++){
		auto add = [&](ll p){
			if(!mp[p]) cot++;
			mp[p]++;
		};
		auto del = [&](ll p){
			mp[p]--;
			if(!mp[p]) cot--;
		};
		auto [l, r, num] = q[i];
		while(rt < r) add(v[++rt]); 
		while(rt > r) del(v[rt--]);
		while(lt < l) del(v[lt++]);
		while(lt > l) add(v[--lt]);
		if(cot == r-l+1) ans[num] = 1;
	}
	for(i = 0; i< m; i++){
		ans[i] ? printf("Yes\n"):printf("No\n");
	}
	return 0;
} 
