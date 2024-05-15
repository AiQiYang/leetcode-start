# 2589. 完成所有任务的最少时间
[题目链接](https://leetcode.cn/problems/minimum-time-to-complete-all-tasks/description/)

## 方法一，贪心法
看到题目之后就想着为了使电脑时间运行最少，则需要尽可能重叠运行任务。那么就想着根据$end_i$从小到大进行排序。对于每个任务来说，从`end`开始最有可能与其他任务重叠（贪心）。

### 代码
````c++
class Solution {
public:
    int findMinimumTime(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(),  [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        int size = tasks.size();
        vector<int> run(tasks[size - 1][1] + 1);
        int res = 0;
        for (auto task : tasks) {
            int start = task[0], end = task[1], duration = task[2];
            duration -= accumulate(run.begin() + start, run.begin() + end + 1, 0);
            for (int i = end; duration > 0 && i >= start; i--) {
                if (run[i] == 0)  {
                    duration--;
                    run[i] = 1;
                    res++;
                }
            }

        }
        return res;
    }
};
````
### 复杂度分析
+ 时间复杂度： $O(n * logn + n * m)$，其中`n`为tasks的长度，`m`为$max(task_{duration})$
+ 空间复杂度：$O(m)$，其中`m`为run数组的长度，根据题目`1 <= starti, endi <= 2000`可知，长度为2001