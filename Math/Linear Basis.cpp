struct XXJ{
    array<ll, 64> base;
    XXJ(){
        for(int i = 0; i < 64; i ++) base[i] = 0;
    }
    bool insert(ll x){    //将集合每个数插入线性基，插入成功则返回true
        for(ll i = 60; i >= 0; i--){
            ll t = (x>>i)&1;
            if(t == 0) continue;
            if(base[i] == 0){
                base[i] = x;
                return true;
            } 
            x ^= base[i];
        }
        return false;
    }
    bool check(ll x){     //检查取该集合任意个数能否异或成x，失败返回false，该操作与线性基的插入同理，不过返回值相反
        for(ll i = 60; i >= 0; i--){
            ll t = (x>>i)&1;
            if(t == 0) continue;
            if(base[i] == 0){
                return false;
            }
            x ^= base[i];
        }
        return true;
    }
};