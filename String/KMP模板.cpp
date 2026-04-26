#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll i, j, n, m;
string s1, s2;
ll ne[1001000];
vector<ll> ans;

void get_ne(string s){
	for(ll i = 1, j = 0; i < s.size(); i++){
		while(s[i] != s[j] && j != 0) j = ne[j-1];
		if(s[i] == s[j]) j++;
		ne[i] = j;
	}
}

/*
	下标从1开始
	for(ll i = 2, j = 1; i < s.size(); i++){
		while(s[i] != s[j] && j != 1) j = ne[j-1];
		if(s[i] == s[j]) j++;
		ne[i] = j;
	}
*/

void match(string s1, string s2){ //匹配
	for(ll i = 0, j = 0; i < s1.size(); i++){
		while(s1[i] != s2[j] && j != 0) j = ne[j-1];
		if(s1[i] == s2[j]) j++;
		if(j == s2.size()) ans.push_back(i-(s2.size()-1)+1), j = ne[j-1];
	}
}

int main(){
	cin >> s1 >> s2;
	get_ne(s2);
	match(s1, s2);
	for(auto it : ans) cout << it << endl;
	for(ll i = 0; i < s2.size(); i++){
		cout << ne[i] << " ";
	}
	return 0;
}
