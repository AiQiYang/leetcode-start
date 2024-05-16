# 1953. 你可以工作的最大周数
[题目链接](https://leetcode.cn/problems/maximum-number-of-weeks-for-which-you-can-work/description/)

## 方法一，贪心
对于这一道题，我们可以发现最长的任务数量如果大于剩下的任务数量加一，就不能继续工作下去了。所以我们有`maxTasks > rest + 1`。

### 代码
````c++
class Solution {
public:
    long long numberOfWeeks(vector<int>& milestones) {
        long long maxTasks = *max_element(milestones.begin(), milestones.end());
        long long rest = accumulate(milestones.begin(), milestones.end(), 0LL) - maxTasks;
        if (maxTasks > rest + 1) {
            return rest * 2 + 1;
        }
        return maxTasks + rest;
    }
};
````

### 复杂度
+ 时间复杂度：$O(n)$，`n`为`milestones`的长度
+ 空间复杂度：$O(1)$