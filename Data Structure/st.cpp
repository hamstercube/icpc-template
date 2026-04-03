//ST表模板
#include <bits/stdc++.h>
using namespace std;
#define lowbit(x) (x&-x)

int n,m,k,kk,u,v;
const int N = 2e5 + 10;
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
