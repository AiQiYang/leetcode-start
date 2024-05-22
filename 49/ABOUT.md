# 49. 字母异位词分组
[题目链接](https://leetcode.cn/problems/group-anagrams/description/?envType=study-plan-v2&envId=top-100-liked)

## 方法一，哈希表
对于这道题我的想法是使用哈希表，将字母异位词映射到同一组里。那么就可以将字符串排序，因为字母异位词是由重新排列源单词的所有字母得到的一个新单词，那么通过排序那么一定是一样的。像"aab", "baa", "aba"通过排序后都是"aab"。那么将排序后的值作为key，排序前的值作为value存储下来。

### 代码
````c++
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> umap;
        for (auto str : strs) {
            string origin = str;
            sort(str.begin(), str.end());
            umap[str].emplace_back(origin);
        }
        vector<vector<string>> res;
        for (auto it = umap.begin(); it != umap.end(); it++) {
            res.emplace_back(it->second);
        }
        return res;
    }
};
````

### 复杂度
+ 时间复杂度：$O(mlogm * n)$，`m`是`strs[i]`的长度，`n`是`strs`的长度
+ 空间复杂度：$O(nm)$