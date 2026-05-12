
求二进制下包含子集的和

```cpp
const int K = 18;
const int S = 1 << K;
long long f[S], g[S];

// 子集和：g[mask] = sum_{sub ⊆ mask} f[sub]
void sos_subset() {
    for (int i = 0; i < K; i++) {
        for (int mask = 0; mask < (1 << K); mask++) {
            if (mask & (1 << i)) {
                f[mask] += f[mask ^ (1 << i)];
            }
        }
    }
}
```