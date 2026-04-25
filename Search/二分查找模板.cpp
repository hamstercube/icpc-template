ll l = 0, r = 2e18;

尽量往小的找 
while(l < r){
	ll mid = l+r>>1;
	if(check(mid)){
		r = mid; 
	}else l = mid-1;
} 

尽量往大的找 
while(l < r){
	ll mid = l+r+1>>1;
	if(check(mid)){
		l = mid;
	}else r = mid+1;
}

lower_bound与upper_bound在有序容器中查询区间个数
 ll be = lower_bound(v.begin(), v.end(), bee)-v.begin();
 ll en = upper_bound(v.begin(), v.end(), enn)-v.begin();
 ll cot = en-be;
 
 lower_bound可以直接查询比x小的数的个数
 upper_bound可以直接查询大于等于x的数的个数 
