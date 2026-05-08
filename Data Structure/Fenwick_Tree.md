树状数组

```cpp
template<class T>
struct BIT {
    vector<T> a;
    int n;

    BIT() {}

    BIT(int n) {
        init(n);
    }

    void init(int n) {
        this->n = n;
        a.assign(n + 1, 0);
    }

    // 【单点加】pos=x 位置 += k
    // ⚠️该函数 和 下方区间加add(x,y,k) 不能混用
    // ⚠️混用会导致答案完全错误
    void add(int x, T k) {
        for (; x <= n; x += x & -x) {
            a[x] += k;
        }
    }

    // 【区间加】[x,y] 全体 += k （差分写法）
    // ⚠️该函数 和 上方单点加add(x,k) 绝对不能混用
    // ⚠️用了这个，ask(x) 变成【单点查询】，不再是前缀和
    void add(int x, int y, T k) {
        add(x, k);
        add(y + 1, -k);
    }

    // 前缀和查询 1~x
    // 模式1：只用单点add(x,k) → ask(x)为前缀和，ask(x,y)为区间和
    // 模式2：只用区间add(x,y,k) → ask(x)为a[x]单点值，禁止用ask(x,y)区间和
    T ask(int x) {
        T ans = 0;
        for (; x > 0; x -= x & -x) {
            ans += a[x];
        }
        return ans;
    }

    // 区间和查询 [x,y]
    // ⚠️仅在【只使用单点add(x,k)】时可用
    // ⚠️如果用过区间add(x,y,k)，禁止调用此函数
    T ask(int x, int y) {
        return ask(y) - ask(x - 1);
    }

    // 权值BIT专用：查询第k小
    // ⚠️单独使用权值场景，不和上面两种修改逻辑混用
    int kth(T k) {
        int pos = 0;
        for (int i = __lg(n); i >= 0; i--) {
            int nxt = pos + (1 << i);
            if (nxt <= n && a[nxt] < k) {
                k -= a[nxt];
                pos = nxt;
            }
        }
        return pos + 1;
    } 
};

/* ---------- 离散化模板 单独使用 和BIT本体无冲突 ----------
// 离散化步骤，用于压缩大数值域，配合权值BIT/线段树使用
// b = a;
// sort(b.begin(), b.end());
// b.erase(unique(b.begin(), b.end()), b.end());
// for (...) {
//     a[i] = lower_bound(b.begin(), b.end(), a[i]) - b.begin() + 1;
// }
*/

/*
===== 最终禁止混用总结 =====
1. 单点add(x,k)  ↔  区间add(x,y,k)   ❌ 严禁混用
2. 用区间加后：只能单点ask(x)，不能区间ask(x,y) ❌
3. kth第k小函数：只用于权值树状数组，不要和普通数组修改混用
4. 离散化：独立工具，和BIT操作无冲突，可正常搭配使用
*/
```