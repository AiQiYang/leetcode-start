# 100297. 找到连续赢 K 场比赛的第一位玩家
[题目描述](https://leetcode.cn/problems/find-the-first-player-to-win-k-games-in-a-row/description/)

## 方法一，双端队列 + 模拟
我的思路是用`deque`来模拟“队列中最前面两名玩家进行一场比赛，技能等级 更高 的玩家胜出。比赛后，获胜者保持在队列的开头，而失败者排到队列的末尾。”这个过程。大概思路就是先把`deque`最前面的两个元素取`pop`出来，比较它们的大小，大的那个插入`dequq`的头，小的插入`deque`的尾。然后当遍历完所有的比赛选手后，在`deque`头里面的肯定是`skill`最高的选手，那么就没有再比下去必要了，即使当前的连胜没有到达`k`，但他肯定会一直赢下去，那么就终止循环。然后我用了哈希表来存储每个skill对应的玩家编号。

````c++
class Solution {
public:
    int findWinningPlayer(vector<int>& skills, int k) {
        unordered_map<int, int> umap;
        for (int i = 0; i < skills.size(); i++) {
            umap[skills[i]] = i;
        }

        int index = 1;
        int count = 0;
        deque<int> deq(skills.begin(), skills.end());
        while (count < k) {
            index++;
            int x = deq.front();
            deq.pop_front();
            int y = deq.front();
            deq.pop_front();
            if (index > skills.size()) {
                deq.push_front(x);
                break;
            } else if (x > y) {
                deq.push_front(x);
                deq.push_back(y);
                count++;
            } else {
                deq.push_front(y);
                deq.push_back(x);
                count = 1;
            }
        }
        return umap[deq.front()];
    }
};
````

### 复杂度
+ 时间复杂度：$O(n)$，`n`是`skills`的长度
+ 空间复杂度：$O(n)$，`n`是`skills`的长度