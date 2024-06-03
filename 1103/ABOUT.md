# 1103. 分糖果 II
[题目链接](https://leetcode.cn/problems/distribute-candies-to-people/description/)

## 方法一，暴力模拟
我的想法是暴力模拟每个人会被分配到多少颗糖,， 代码如下。主要的难点是`min(candy, candies)`，因为分到最后一位时会出现可能剩下的糖比他应该得到的糖要少了，那他只能拿到剩下的糖而不是拿到他应该拿到的糖的数量。

### 代码
````c++
class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> res(num_people, 0);
        int index = 0;
        int candy = 1;
        while (candies) {
            res[index % num_people] += min(candy, candies);
            candies -= min(candy, candies);
            index++;
            candy++;
        }
        return res;
    }
};
````

### 复杂度
+ 时间复杂度：$O(\sqrt{candies})$，`n`是candies
+ 空间复杂度：$O(1)$
