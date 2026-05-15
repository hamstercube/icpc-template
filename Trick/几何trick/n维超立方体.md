
### n 维超立方体，其表面上 m 维超立方体的数量公式为：

$$
\boxed{
\text{答案} = 2^{n-m} \times \binom{n}{m}
}
$$

---

### 体积、表面积公式（单位超立方体，边长为 1）

- **体积**：
$$
V_n = 1^n = 1
$$

- **表面积**：
$$
S_n = 2n \cdot 1^{n-1} = 2n
$$
（n 维超立方体的“面”是 n-1 维超立方体，共 2n 个）

---

## n 维球体核心公式

### 1. 体积公式（半径为 \( r \) 的 n 维球）

\[
V_n(r) = \frac{\pi^{n/2}}{\Gamma\left(\frac{n}{2}+1\right)} r^n
\]

- 当 \( n \) 为偶数时：\( \Gamma(k+1) = k! \)，比如 \( n=2k \) 时：
\[
V_{2k}(r) = \frac{\pi^k}{k!} r^{2k}
\]

- 当 \( n \) 为奇数时：\( \Gamma\left(k+\frac{1}{2}\right) = \frac{(2k)!}{4^k k!} \sqrt{\pi} \)，比如 \( n=2k+1 \) 时：
\[
V_{2k+1}(r) = \frac{2^{k+1} \pi^k}{(2k+1)!!} r^{2k+1}
\]

### 2. 表面积公式（n 维球的“表面”是 n-1 维球面）

\[
S_n(r) = \frac{2\pi^{n/2}}{\Gamma\left(\frac{n}{2}\right)} r^{n-1}
\]

- 关系：\( S_n(r) = \frac{d}{dr} V_n(r) \)，即表面积是体积对半径的导数。

---

## n 维空间的距离与范数

### 1. 常见距离公式（$\mathbf{x} = (x_1, \dots, x_n), \mathbf{y} = (y_1, \dots, y_n)$）

- **曼哈顿距离（L1 范数）**：
$$
d_1(\mathbf{x}, \mathbf{y}) = \sum_{i=1}^n |x_i - y_i|
$$

- **欧氏距离（L2 范数）**：
$$
d_2(\mathbf{x}, \mathbf{y}) = \sqrt{\sum_{i=1}^n (x_i - y_i)^2}
$$

- **切比雪夫距离（L∞ 范数）**：
$$
d_\infty(\mathbf{x}, \mathbf{y}) = \max_{i=1..n} |x_i - y_i|
$$

---

### 2. 范数通用公式（Lp 范数）

$$
d_p(\mathbf{x}, \mathbf{y}) = \left( \sum_{i=1}^n |x_i - y_i|^p \right)^{1/p}
$$

$p=1、2、\infty$ 分别对应上面三种距离。