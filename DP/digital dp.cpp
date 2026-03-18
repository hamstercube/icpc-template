#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n;
ll dp[200100][10][2];

// 核心思维：小于等于R且满足条件的个数减小于等于L且满足的个数，还验证L本身是不是满足条件
// 要注意处理前导0

ll dfs(string &s, ll p, ll len, ll pre, ll free){ // s：L或R, p：从前往后第p位数，len: 还有多少位未填，pre: 条件，free：是否需要约束 
    if(!len){
        if(pre) return 1; // 成功条件
        else return 0;
    }
    if(dp[len][pre][free]!= -1) return dp[len][pre][free]; //记忆化搜索
    ll res = 0, lim = 9;
    if(!free) lim = s[p]-'0'; // 设置上界
    for(ll i = 0; i <= lim; i++){
        if(!free && i==lim){
            res += dfs(p+1, len-1, pre, 0); //pre要根据条件处理
            //根据条件处理前导0
        }
        else{
            res += dfs(p+1, len-1, pre, 1); //pre要根据条件处理
            //根据条件处理前导0
        }
    }
    return dp[len][pre][free] = res; 
}

bool check(ll x){
    //检查L是否满足条件
}

int main(){
    string s[2];
    ll cot[2] = {0};
    for(ll i = 0; i < 2; i++){
        cin >> s[i];
        memset(dp, -1, sizeof dp);
        cot[i] = dfs(s[i], 0, s.size(), ll pre, 0); // pre为条件
    }
    cout << cot[1]-cot[0]+check(s[0]);
    return 0;
}
