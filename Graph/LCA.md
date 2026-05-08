```cpp
#include <bits/stdc++.h>

using namespace std;

const int N = 2e6 + 10;

vector<int> v[N];
int dep[N];
int fa[N][32];
int w[N];
int sum[N];

void dfs(int root,int fno){
    dep[root] = dep[fno] + 1;
    fa[root][0] = fno;
    for(int i = 1; i < 31; i ++){
        fa[root][i] = fa[fa[root][i - 1]][i - 1];
    }
    for(auto it : v[root]){
        if(it != fno){
            dfs(it,root);
        }
    }
}

int find(int root,int cnt){
    int ans = root;
    for(int i = 0; cnt; i ++,cnt >>= 1){
        if(cnt & 1) ans = fa[ans][i]; 
    }
    return ans;
}

void dfst(int root,int fno){
    int l,r;
    l = root;
    r = find(root,w[root]);
    sum[l] ++;
    r = fa[r][0];
    sum[r] --;   
    for(auto it : v[root]){
        if(it == fno)continue;
        dfst(it,root);
        sum[root] += sum[it];
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i < n; i ++){
        int x,y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(1,0);
    for(int i = 1; i <= n; i ++){
        cin >> w[i];
    }
    dfst(1,0);
    for(int i = 1; i <= n; i ++)cout << sum[i] << " ";
    return 0;
}
```