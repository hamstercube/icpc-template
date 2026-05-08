```cpp

//埃氏筛:
const int N = 1;
int primes[N], cnt; 
bool st[N]; 
void get_primes(int n) 
{ 
    for (int i = 2; i <= n; i ++ ) 
    { 
        if (st[i]) continue; 
        primes[cnt ++ ] = i; 
        for (int j = i + i; j <= n; j += i) 
            st[j] = true; 
    } 
} 


```