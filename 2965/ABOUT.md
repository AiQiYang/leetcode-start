# 2965. 找出缺失和重复的数字
[题目链接](https://leetcode.cn/problems/find-missing-and-repeated-values/description/)

## 方法一，哈希表
一开始看到这一题，就想着可以使用一个数组，存储所有元素的出现次数，如何查询一下这个数组谁出现了0次，谁出现了2次就可以了

### 代码
````c++
class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int size = grid[0].size();
        vector<int> rec(size*size+1, 0);
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                rec[grid[i][j]]++;
            }
        }
        vector<int> res(2);
        for (int i = 0; i < rec.size(); i++) {
            if (rec[i] == 2) {
                res[0] = i;
            }
            if (rec[i] == 0) {
                res[1] = i;
            }
        }
        return res;
    }
};
````

### 复杂度
+ 时间复杂度$O(n^2)$，n是矩阵的行数/列数
+ 空间复杂度$O(n^2)$