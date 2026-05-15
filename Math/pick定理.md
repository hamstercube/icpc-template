# Pick 定理

Pick 定理：给定顶点均为整点的简单多边形，皮克定理说明了其面积 $A$ 和内部格点数目 $i$、边上格点数目 $b$ 的关系：
$$
A = i + \frac{b}{2} - 1.
$$

它有以下推广：
- 取格点的组成图形的面积为一单位。在平行四边形格点，皮克定理依然成立。套用于任意三角形格点，皮克定理则是 $A = 2 \times i + b - 2$。
- 对于非简单的多边形 $P$，皮克定理 $A = i + \frac{b}{2} - \chi(P)$，其中 $\chi(P)$ 表示 $P$ 的欧拉特征数。
- 高维推广：Ehrhart 多项式
- 皮克定理和欧拉公式（$V - E + F = 2$）等价。

# 一道例题（POJ 1265）

## 题目大意
在直角坐标系中，一个机器人从任意点出发进行 $n$ 次移动，每次向右移动 $dx$，向上移动 $dy$，最后会形成一个平面上的封闭简单多边形，求边上的点的数量，多边形内的点的数量，多边形面积。

---

## 题解
这道题目其实用了以下三个知识：
- 以整点为顶点的线段，如果边 $dx$ 和 $dy$ 都不为 $0$，经过的格点数是 $\gcd(dx, dy) + 1$。如果要算一整个图形的，多加的点会被上一条边计算，也就不需要加了。那么一条边覆盖的点的个数为 $\gcd(dx, dy)$，其中，$dx, dy$ 分别为线段横向占的点数和纵向占的点数。如果 $dx$ 或 $dy$ 为 $0$，则覆盖的点数为 $dy$ 或 $dx$。
- Pick 定理：平面上以整点为顶点的简单多边形的面积 = 边上的点数 $/2 +$ 内部的点数 $- 1$。
- 任意一个多边形的面积等于按顺序求相邻两个点与原点组成的向量的叉积之和的一半（这个也可以通过顺时针定积分求得）。

```cpp
#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;
constexpr int MAXN = 110;

struct node {
  int x, y;
} p[MAXN];

// 求最大公约数
int gcd(int x, int y) { return y == 0 ? x : gcd(y, x % y); }

// 求区域
int area(int a, int b) { return p[a].x * p[b].y - p[a].y * p[b].x; }

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t, ncase = 1;
  cin >> t;
  while (t--) {
    int n, dx, dy, x, y, num = 0, sum = 0;
    cin >> n;
    p[0].x = 0, p[0].y = 0;
    for (int i = 1; i <= n; i++) {
      cin >> x >> y;
      p[i].x = x + p[i - 1].x, p[i].y = y + p[i - 1].y;
      dx = x, dy = y;
      if (x < 0) dx = -x;
      if (y < 0) dy = -y;
      num += gcd(dx, dy);
      sum += area(i - 1, i);
    }
    if (sum < 0) sum = -sum;
    cout << fixed << setprecision(1);
    cout << "Scenario #" << ncase++ << ":\n";
    cout << ((sum - num + 2) >> 1) << ' ' << num << ' ' << sum * 0.5 << "\n\n";
  }
  return 0;
}
```