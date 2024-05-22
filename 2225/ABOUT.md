# 2225. 找出输掉零场或一场比赛的玩家
[题目链接](https://leetcode.cn/problems/find-players-with-zero-or-one-losses/description/)

## 方法一，哈希表
对于这道题，我的思路是用一个哈希表来保存所有Player输了多少场。  
+ 那么我们需要初始化`unordered_map`并将输了的Player的次数记入下来`umap[match[1]]++;`，这里`match[1]`就是该场的Loser。  
+ 接下来通过查询`unordered_map->second`谁等于`0`，谁等于`1`来判断谁没有输掉任何比赛，谁恰好输掉一场比赛。

### 代码
````c++
class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, int> umap;
        vector<int> ans0;
        vector<int> ans1;
        for (auto match : matches) {
            if (umap.find(match[0]) == umap.end()) {
                umap[match[0]] = 0;
            }
            umap[match[1]]++;
        }
        
        for (auto it = umap.begin(); it != umap.end(); it++) {
            if (it->second == 0) {
                ans0.push_back(it->first);
            } else if (it->second == 1) {
                ans1.push_back(it->first);
            }
        }
        vector<vector<int>> res;
        sort(ans0.begin(), ans0.end());
        sort(ans1.begin(), ans1.end());
        res.push_back(ans0);
        res.push_back(ans1);
        return res;
    }
};
````

### 复杂度
+ 时间复杂度：$O(n*logn)$，`n`是matches的长度
+ 空间复杂度：$O(n)$，`n`是matches的长度