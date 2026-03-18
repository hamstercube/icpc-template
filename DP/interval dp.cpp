#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll dp[310][310];   //区间dp最大的特点就数据量为百位
ll i, j, n, m; 

int main(){
	cin >> n;
	for( i = 1; i <= n; i++){
		ll t;
		cin >> t;
		dp[i][i][1] = t;
	}
	for(ll len = 2; len <= n; len++){ //环形区间dp就在后面复制一层
		for(ll l = 1; l <= n-len+1; l++){
			ll lt = l, rt = l+len-1;
			for(ll k = lt; k < rt; k++){
				// dp方程
			}
		}
	}
	cout << dp[1][n][0]; 
	return 0;
}
