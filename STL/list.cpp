#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

int main()
{
    // ===================== 初始化 =====================
    list<int> l;                     // 空链表
    list<int> l1(10);                // 10个默认值0
    list<int> l2(5, 6);              // 5个6
    list<int> l3 = {1, 2, 3, 4};     // 列表初始化
    list<int> l4(l3);                // 拷贝构造

    // ===================== 元素访问 =====================
    l3.front();   // 返回首元素引用
    l3.back();    // 返回尾元素引用

    // ===================== 插入操作 =====================
    l3.push_front(0);               // 头部插入
    l3.push_back(5);                // 尾部插入

    auto it = l3.begin();
    ++it;
    // insert(迭代器位置, 值) 返回【新元素迭代器】
    auto new_it = l3.insert(it, 99);
    // 插入 n 个相同元素
    l3.insert(l3.begin(), 2, 77);

    // 原地构造
    l3.emplace_front(100);
    l3.emplace_back(200);
    l3.emplace(it, 300);

    // ===================== 删除操作 =====================
    l3.pop_front();
    l3.pop_back();

    // erase：删除迭代器元素，返回【下一个元素迭代器】
    auto next_it = l3.erase(new_it);

    // 删除区间 [begin, end)
    l3.erase(l3.begin(), next_it);

    l3.remove(2);                    // 删除所有值为2的元素
    l3.remove_if([](int x){return x > 100;});
    l3.clear();                     // 清空链表

    // ===================== 容量相关 =====================
    l3.empty();      // 是否为空 bool
    l3.size();       // 元素个数 size_t
    l3.max_size();   // 最大容量

    // ===================== 迭代器 =====================
    auto b_it = l3.begin();
    auto e_it = l3.end();
    auto rb_it = l3.rbegin();
    auto re_it = l3.rend();

    // 常量迭代器
    auto cb_it = l3.cbegin();
    auto ce_it = l3.cend();

    // ===================== 链表常用操作 =====================
    list<int> a = {3,1,4,2};
    a.sort();                        // 升序
    a.sort(greater<int>());          // 降序
    a.reverse();                     // 反转
    a.unique();                      // 去连续重复(先排序)

    list<int> b = {5,7,6};
    a.merge(b);                      // 合并有序链表，b置空
    a.splice(a.begin(), b);           // 节点转移

    a.assign(3, 10);                 // 覆盖：3个10
    a.assign(l2.begin(), l2.end());

    // ===================== 遍历写法 =====================
    // 1. 范围for
    for (auto x : a)
    {
        cout << x << " ";
    }
    cout << "\n";

    // 2. 迭代器遍历
    for (auto it = a.begin(); it != a.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << "\n";

    // ===================== find 查找 =====================
    list<int> nums = {10,20,30,40};
    auto find_it = find(nums.begin(), nums.end(), 30);
    if (find_it != nums.end())
    {
        // 找到元素
    }

    return 0;
}