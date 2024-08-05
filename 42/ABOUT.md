# 42. 接雨水
[题目链接](https://leetcode.cn/problems/trapping-rain-water/description/?envType=study-plan-v2&envId=top-100-liked)

## 方法一，双指针
对于这道题，我参考了@[灵茶山艾府](https://leetcode.cn/problems/trapping-rain-water/solutions/1974340/zuo-liao-nbian-huan-bu-hui-yi-ge-shi-pin-ukwm/)的题解。是先从前缀和后缀最大值出发，对存储值优化的版本。大致思路是，计算每一个单元格的存水量，但是每个单元格的存水量与左边所有的单元格的最大值和右边所有单元格的最大值这两个值的最小值有关。那么我们就可以利用双指针，只有当右边所有单元格的最大值大于左边所有单元格的最大值时，那么就可以确定左边那个指针所指向的那个单元格的存水量。

### 代码
````c++
class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;

        int prefix = 0;
        int suffix = 0;

        int res = 0;

        while (left < right) {
            prefix = max(prefix, height[left]);
            suffix = max(suffix, height[right]);

            if (prefix <= suffix) {
                res += prefix - height[left++];
            } else {
                res += suffix - height[right--];
            }
        }
        return res;
    }
};
````

### 复杂度
+ 时间复杂度：$O(n)$, `n`是`height`数组的大小
+ 空间复杂度：$O(1)$