#include <bits/stdc++.h>
using namespace std;

// 从网格图任意一点出发遍历每个点一次

void solve() {
    int n, m, r0, c0;
    cin >> n >> m >> r0 >> c0;
    vector<vector<pair<int, int>>> nex(n + 1, vector<pair<int, int>>(m + 1));
    for (int j = 1; j < m; j++) {
        nex[1][j] = {1, j + 1};
    }
    if (m % 2 == 0) { //构造方向图
        for (int j = 1; j <= m; j++) {
            if (j % 2 == 1) {
                for (int i = n; i > 2; i--) {
                    nex[i][j] = {i - 1, j};
                }
                if (j + 1 <= m) {
                    nex[n][j + 1] = {n, j};
                }
            } else {
                for (int i = 2; i < n; i++) {
                    nex[i][j] = {i + 1, j};
                }
                if (j + 1 <= m) {
                    nex[2][j + 1] = {2, j};
                }
            }
        }
        nex[2][1] = {1, 1};
        nex[1][m] = {2, m};
    } else {
        for (int j = 1; j <= m - 2; j++) {
            if (j % 2 == 1) {
                for (int i = n; i > 2; i--) {
                    nex[i][j] = {i - 1, j};
                }
                if (j + 1 <= m) {
                    nex[n][j + 1] = {n, j};
                }
            } else {
                for (int i = 2; i < n; i++) {
                    nex[i][j] = {i + 1, j};
                }
                if (j + 1 <= m) {
                    nex[2][j + 1] = {2, j};
                }
            }
        }
        nex[2][1] = {1, 1};
        nex[1][m] = {2, m};
        for (int i = 2; i < n; i++) {
            if (i % 2 == 1) {
                nex[i][m - 1] = {i, m};
                nex[i][m] = {i + 1, m};
            } else {
                nex[i][m - 1] = {i + 1, m - 1};
                nex[i][m] = {i, m - 1};
            }
        }
        nex[n][m - 1] = {n, m - 2};
        nex[n][m] = {n, m - 1};
    }
    // int r1, c1;
    // cin >> r1 >> c1;
    // string ans;
    // int cnt = 0;
    // while (1) {
    //     if (r1 == r0 && c1 == c0) {
    //         cout << ans << endl;
    //         ans = "";
    //         cnt++;
    //         if (cnt == n * m - 1) {
    //             return;
    //         }
    //         cin >> r1 >> c1;
    //     }
    //     if (m % 2 == 1 && r1 == n && c1 == m && c0 == m && r0 == n - 1) {
    //         ans += 'D';
    //         r0++;
    //         continue;
    //     }
    //     if (nex[r0][c0] == make_pair(r0 - 1, c0)) {
    //         ans += 'U';
    //     } else if (nex[r0][c0] == make_pair(r0 + 1, c0)) {
    //         ans += 'D';
    //     } else if (nex[r0][c0] == make_pair(r0, c0 - 1)) {
    //         ans += 'L';
    //     } else {
    //         ans += 'R';
    //     }
    //     auto [r2, c2] = nex[r0][c0];
    //     r0 = r2, c0 = c2;
    //     cout << r0 << " " << c0 << endl;
    // }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}