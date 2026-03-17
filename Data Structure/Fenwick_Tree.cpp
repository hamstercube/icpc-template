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

    void add(int x, T k) {
        for (; x <= n; x += x & -x) {
            a[x] += k;
        }
    }

    void add(int x, int y, T k) {
        add(x, k);
        add(y + 1, -k);
    }

    T ask(int x) {
        T ans = 0;
        for (; x > 0; x -= x & -x) {
            ans += a[x];
        }
        return ans;
    }

    T ask(int x, int y) {
        return ask(y) - ask(x - 1);
    }

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
    } // 第k小
};


// b = a;
// sort(b.begin(), b.end());
// b.erase(unique(b.begin(), b.end()), b.end());
// for (...) {
//     a[i] = lower_bound(b.begin(), b.end(), a[i]) - b.begin() + 1;
// }
// 离散化模板代码