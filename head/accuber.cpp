//ST表模板
#include <bits/stdc++.h>
#define int long long
#define PII pair<int,int>
#define fi first
#define se second
#define endl "\n"

#define lc (p<<1)
#define rc (p<<1|1)
#define lowbit(x) (x&-x)

#define debug(x) cout<<#x<<":"<<x<<endl
using namespace std;

const int N=2e5+10,M=1010,mod=998244353,INF=0x3f3f3f3f;
const int inf=0x3f3f3f3f3f3f3f3f;
const double eps=1e-6;

int dx[]={0,1,0,-1},dy[]={1,0,-1,0};
int n,m,k,kk,u,v;
int f[18][N],Log[N],a[N];

void init(){
    Log[0]=-1;
    for(int i=1;i<=n;i++){
        Log[i]=lowbit(i)==i?(Log[i-1]+1):Log[i-1];
        f[0][i]=a[i];
    }
    for(int i=1;i<=Log[n];i++)
        for(int j=1;j+(1<<i)-1<=n;j++)
            f[i][j]=max(f[i-1][j],f[i-1][j+(1<<i-1)]);
}

inline int stmax(int l,int r){
    int k=Log[r-l+1];
    return max(f[k][l],f[k][r-(1<<k)+1]);
}

void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    init();
    cin>>m;
    while(m--){
        cin>>u>>v;
        cout<<stmax(u,v)<<endl;
    }
}

signed main(){
    ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
    int _=1;
    //cin>>-;
    while(_--)solve();
    return 0;
}
