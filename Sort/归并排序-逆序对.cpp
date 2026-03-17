#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n;int ans=0;int a[N];int tmp[N];
void mer(int l,int r)
{
    if(l>=r)return;
    int mid=l+r>>1;
    mer(l,mid),mer(mid+1,r);
    int i=l,j=mid+1,idx=0;
    while(i<=mid&&j<=r)
    {
        if(a[i]<=a[j])tmp[idx++]=a[i++];
        else
        {
            ans+=mid-i+1;//关键
            tmp[idx++]=a[j++];
        }
    }
    while(i<=mid)tmp[idx++]=a[i++];
    while(j<=r)tmp[idx++]=a[j++];
    for(int i=l,j=0;i<=r;i++,j++)a[i]=tmp[j];
}
signed main()
{
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    mer(1,n);
    cout<<ans;
    return 0;
}