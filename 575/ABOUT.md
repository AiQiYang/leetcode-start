# 575. 分糖果
[题目链接](https://leetcode.cn/problems/distribute-candies/description/)

## 方法一，哈希表
我们可以使用一个数据结构，那个数据结构可以消除重复元素，这样我们就得到了所有糖果的种类数即那个数据结构的`size`。最后只要和`n / 2`一比，就可以得到答案了。这个数据结构就是`unordered_set<int>`

### 代码
````c++
class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_set<int> type(candyType.begin(), candyType.end());
        int candies = candyType.size() / 2;
        int types = type.size();
        return min(candies, types);
    }
};
````

### 复杂度
+ 时间复杂度：$O(n)$，`n`为candyType的`size`
+ 空间复杂度：$O(n)$, `n`为candyType的`size`