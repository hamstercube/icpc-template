求树的直径

```cpp
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,d[N],du[N],dv[N];
vector<int>g[N];
void dfs(int x,int fa){
    for(int y:g[x]){
        if(y==fa)continue;
        d[y]=d[x]+1;
        dfs(y,x);
    }
}
signed main(){
	cin>>n;
    for(int i=1,x,y;i<n;i++){
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    int u=1,v;
	memset(d,0,sizeof d);
    dfs(1,-1);
    for(int i=1;i<=n;i++){
    	if(d[i]>=d[u])u=i;
	}
	memset(d,0,sizeof d);
    dfs(u,-1);
    for(int i=1;i<=n;i++)du[i]=d[i];
    v=u;
    for(int i=1;i<=n;i++){
    	if(d[i]>=d[v])v=i;
	}
	memset(d,0,sizeof d);
    dfs(v,-1);
    for(int i=1;i<=n;i++)dv[i]=d[i];
    for(int i=1;i<=n;i++){
        if(du[i]>dv[i])cout<<u<<"\n";
        else if(dv[i]>du[i])cout<<v<<"\n";
        else cout<<max(u,v)<<"\n";
    }
	return 0;
}
```