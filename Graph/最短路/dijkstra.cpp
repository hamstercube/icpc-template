#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5 + 10;

vector<pair<int,int>> g[N];
vector<int> vis(N);
vector<int> dist(N,1e10);

void dijkstra(int x){
    dist[x] = 0;
    priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>> > heap;
    heap.push({0,x});
    while(!heap.empty()){
        auto [d,idx] = heap.top();
        heap.pop();
        if(vis[idx])continue;
        vis[idx] = true;
        for(auto [jidx,jw] : g[idx]){
            int sum = dist[idx] + jw;
            if(dist[jidx] > sum){
                dist[jidx] = sum;
                if(!vis[jidx]){
                    heap.push({sum,jidx});
                }
            }
        }
    }
}

signed main(){
    ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
    int n,m,s;
    cin >> n >> m >> s;
    while(m --){
        int u,v,w;
        cin >> u >> v >> w;
        g[u].push_back({v,w});
    }
    dijkstra(s);
    for(int i = 1; i <= n; i ++){
        cout << dist[i] << " ";
    }
    return 0;
}