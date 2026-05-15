LRUD Moving
网格遍历，从（1， 1）遍历到（n，n）不经过（x, y）点

```cpp
#include<bits/stdc++.h> 
#define endl '\n'
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
mt19937_64 rnd(time(0));

ll i, j, n, m, a, b;

void solve(){
    cin >> n >> a >> b;
    if(n%2 == 1 || (a+b)%2 == 0){
        cout << "No" << endl;
        return ;
    }
    cout << "Yes" << endl;
    for(ll i = 1; i <= (a-1)/2; i++){
        for(ll j = 1; j < n; j++){
            cout << "R";
        }
        cout << "D";
        for(ll j = 1 ; j < n; j++){
            cout << "L";
        }
        cout << "D";
    }
    for(ll i = 0, p = 1, lt = 1;  lt <= 2*n-2; i++, lt++){
        if(p == b && lt <= 2*n-1){
            cout << "R";
            i--, p++;
        } else if(i%4 == 0){
            cout << "D";
        } else if(i%4 == 2){
            cout << "U";
        } else  cout << "R", p++;
    }
    if((n-a-a%2)/2) cout << "D";
    for(ll i = 1; i <= (n-a-a%2)/2; i++){
        for(ll j = 1; j < n; j++){
            cout << "L";
        }
        cout << "D";
        for(ll j = 1 ; j < n; j++){
            cout << "R";
        }
        if(i != (n-a-a%2)/2) cout << "D";
    }
    cout << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    ll T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}
```