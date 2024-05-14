# 3146. 两个字符串的排列差
[题目链接](https://leetcode.cn/problems/permutation-difference-between-two-strings/description/)

## 方法一，哈希表
一开始想到的是使用嵌套循环，但是这样的时间复杂度会比较高到达了$O(n^2)$。那么我就想怎么可以减少时间复杂度，于是想到了使用数组或哈希表先存储一个字符串中每个字符的位置，然后再遍历另一个字符串，计算每个字符的排列差。

### 解题方法
这里最重要的是选择一个数据结构能够高效的存和取其值。由于字符的大小是固定的，26个字母，那么可以选择使用数组，大小为26来存储。但是我直接使用了unordered_map。那么步骤如下：
1. 遍历一遍`t/s`数组
2. 将里面的元素及其位置存下来`umap_t[t[i]] = i;`
3. 再遍历另一个字符串
4. 计算每一个位置上的字符与另一个字符串中相同元素在另一个字符串上面的位置的差`int index_t = umap_t[s[i]]; res += abs(i - index_t);`

### 代码
````c++
class Solution {
public:
    int findPermutationDifference(string s, string t) {
        unordered_map<int, int> umap_t;
        int length = t.size();
        int res = 0;
        for (int i = 0; i < length; i++) {
            umap_t[t[i]] = i;
        }
        for (int i = 0; i < length; i++) {
            int index_t = umap_t[s[i]];
            res += abs(i - index_t);
        }
        return res;
    }
};
````

### 复杂度
+ 时间复杂度：$O(n)$，`n`为字符串s/t的长度
+ 空间复杂度：$O(1)$，因为s仅有小写字母组成，那就是26，与输入字符串的长度无关