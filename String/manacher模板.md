```cpp
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int ans = 0;
int rt[30000100];
string s, s1 = "$#";


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> s;
    for(int i = 0; i < s.size(); i++) s1+=s[i],s1+='#'; // i*2就是原串的字符在新串的位置
    s1 += '^';
    for(int i = 1, c = 1, r = 1; i < s1.size(); i++){
		if(i <= r) rt[i] = min(rt[(c<<1)-i], r-i);
		else rt[i] = 1; 
		while(s1[i+rt[i]] == s1[i-rt[i]]) rt[i]++;
		if(i+rt[i]-1 > r) c = i, r = i+rt[i]-1;
		ans = max(ans, rt[i]-1); //得出来新串里每个回文都是奇数长度的，而实际为一半-1
	}
    cout << ans;
    return 0;
}
```
