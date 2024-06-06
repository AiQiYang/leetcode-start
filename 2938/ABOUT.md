# 2938. 区分黑球与白球
[题目链接](https://leetcode.cn/problems/separate-black-and-white-balls/description/)

## 方法一，贪心
我的想法是可以先从右往左遍历，这样碰到的黑球的右边肯定是白球，这样就不影响黑球的移动，如何移动的距离是当前右边第一个白球的位置减去该黑球的位置。  
这里`right`记录的是右边第一个白球所在的位置

### 代码
````c++
class Solution {
public:
    long long minimumSteps(string s) {
        int s_size = s.size();
        long long steps = 0;
        int right = s_size - 1;
        for (int i = s_size - 1; i >= 0; i--) {
            if (s[i] == '1') {
                steps += right - i;
                right--;
            }
        }
        return steps;
    }
};
````

### 复杂度
+ 时间复杂度：$O(n)$，`n`是`s`的长度
+ 空间复杂度：$O(1)$

## 方法二，贪心
该方法参考了[灵茶山艾府](https://leetcode.cn/problems/separate-black-and-white-balls/solutions/2532930/lei-jia-mei-ge-0-zuo-bian-de-1-de-ge-shu-luuh/)的题解。
该思路就是所有的`0`都会因为`0`左边的`1`要移动而增加移动次数。而具体的移动次数是多少看该`0`左边的`1`有几个

### 代码
````python
class Solution:
    def minimumSteps(self, s: str) -> int:
        steps = count1 = 0
        for c in s:
            if c == '1':
                count1 += 1
            else:
                steps += count1

        return steps
````

### 复杂度
+ 时间复杂度：$O(n)$，`n`是`s`的长度
+ 空间复杂度：$O(1)$