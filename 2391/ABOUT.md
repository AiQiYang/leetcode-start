# 2391. 收集垃圾的最少总时间
[题目链接](https://leetcode.cn/problems/minimum-amount-of-time-to-collect-garbage/)

## 方法一，多次遍历
先让垃圾车跑完全程，然后再倒着往前减去多跑点时间。  
代码如下：
````c++
class Solution1 {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        // There are 3 garbage trucks, so we need times 3
        int totalTime = accumulate(travel.begin(), travel.end(), 0) * 3;
        // Calculate the total time to clear all garbage
        for (string gar : garbage) {
            totalTime += gar.size();
        }
        // Subtract the excess distance traveled by each car
        for (char g : {'G', 'P', 'M'}) {
            int index = garbage.size() - 1;
            while (index && garbage[index].find(g) == std::string::npos) {
                totalTime -= travel[index - 1];
                index--;
            }
        }
        return totalTime;
    }
};
````

## 方法二，一次遍历
与方法一相似，改进之处在于加入一个存储的数据结构，这里使用了数组。这个数组存储了'G', 'M', 'P'中每个元素最后一次出现的位置（到达起始点的距离）
````c++
class Solution2 {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int times[4]{};
        int travelCost = 0;
        int totalTime = garbage[0].size();
        for (int i = 1; i < garbage.size(); i++) {
            travelCost += travel[i - 1];
            totalTime += garbage[i].size();
            for (char c : garbage[i]) {
                times[c & 3] = travelCost;
            }
        }
        totalTime += accumulate(times, times + 4, 0);
        return totalTime;

    }
};
````