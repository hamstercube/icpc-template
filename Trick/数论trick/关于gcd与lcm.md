
GCD:

1.当x可以整除a*b且y可以整除a*b,则gcd(x, y)可以整除a*b

2.当求取k个元素的最大gcd时, 如果数据范围合法,那么可以通过直接给每个数的因数记数来求


LCM：

1.lcm(a, b) = a*b/gcd(a, b)

2.lcm(a, b, c) = a*b*c/(gcd( a, b)*gcd(b, c) * gcd(a, c)*gcd(a, b, c)) = lcm(a, b)*c/gcd(lcm(a, b), c)

3.多个数的lcm为每个数质因数分解后，出现的每个质因数的最大次幂之积，最大次幂由每个元素的单独贡献来记哦！