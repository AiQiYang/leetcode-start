#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        unordered_map<int, int> umap;
        for (auto num : nums) {
            umap[num]++;
        }
        int res = 0;
        int counter = 0;
        for (const auto& pair : umap) {
            counter++;
            int num = pair.first;
            int count = pair.second;
            if (count == 2) {
                if (counter == 1) {
                    res = num;
                } else {
                    res ^= num;
                }
            }
        }
        return res;
    }
};

int main() {
    Solution solution;

    // 测试案例 1
    vector<int> nums1 = {2, 4, 3, 6, 3, 2, 5, 5};
    cout << "Test Case 1: " << solution.duplicateNumbersXOR(nums1) << endl; // 应该输出重复的数字

    // 测试案例 2
    vector<int> nums2 = {1, 2, 1, 3};
    cout << "Test Case 2: " << solution.duplicateNumbersXOR(nums2) << endl; // 应该输出重复的数字

    // 测试案例 3
    vector<int> nums3 = {};
    cout << "Test Case 3: " << solution.duplicateNumbersXOR(nums3) << endl; // 空数组，根据题意可能需要特殊处理

    // 可以添加更多的测试案例

    return 0;
}