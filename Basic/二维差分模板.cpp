
标记： 
auto change = [&](ll x, ll y, ll xt, ll yt){
		mp[x][y]++;
		mp[x][yt+1]--;
    	mp[xt+1][y]--;
		mp[xt+1][yt+1]++;
};

还原：
mp[x][y] = mp[x-1][y]+mp[x][y-1]+mp[x-1][y-1]+mp[x][y]; 
