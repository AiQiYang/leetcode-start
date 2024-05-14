#  2244. 完成所有任务需要的最少轮数
[题目链接](https://leetcode.cn/problems/minimum-rounds-to-complete-all-tasks/description/)
## 方法一，贪心
本题使用了贪心的思想，就是尽可能多完成3个相同难度级别的任务。 \\
那么我们就可以进行分类讨论：
设tasks的长度位length，我们有
+ `length = 1`：对于这种情况，无法完成任务，返回`-1`
+ `length = 3 * k`，其中`k`为正整数，这种情况就是说可以被`3`整除，则返回`k`
+ `length = 3 * k + 1`，其中$k \geq 1$, 这种情况是`4, 7, 10`，分析一下可知道可以有`k - 1`个3和`3 * k + 1 - 3 * (k - 1) = 4`就是`2`个`2`组成，`k - 1 + 2 = k + 1`。
+ `length = 3 * k + 2`，其中`k`为正整数，这种情况就是由`k`个`3`和`1`个`2`组成，`k + 1`。

### 代码
````c++
class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> umap;
        for (int i = 0; i < tasks.size(); i++) {
            umap[tasks[i]]++;
        }
        int res = 0;
        for (auto [_, fre] : umap) {
            // cout << "fre" << fre << " with num: " << num << endl;
            if (fre == 1) {
                return -1;
            } else if (fre % 3 == 0) {
                res += fre / 3;
            } else {
                res += fre / 3 + 1;
            }
        }
        return res;
    }
};
````

### 复杂度
+ 时间复杂度：$O(n)$，n为tasks的长度
+ 空间复杂度：$O(n)$，n为不同种类的任务数量