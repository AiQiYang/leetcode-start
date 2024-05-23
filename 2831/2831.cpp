#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        unordered_map<int, vector<int>> umap;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            umap[nums[i]].push_back(i);
        }

        int res = 0;
        for (auto& pair : umap) {
            for (int i = 0, j = 0; i < pair.second.size(); i++) {
                while (pair.second[i] - pair.second[j] - (i - j) > k) j++;
                res = max(res, i - j + 1);
            }
        }

        return res;
    }
};

int main() {
    Solution solution;

    vector<int> nums1 = {1, 2, 3, 1, 2, 3, 4, 5, 6, 7, 1};
    int k1 = 3;
    cout << "Test Case 1: " << solution.longestEqualSubarray(nums1, k1) << endl;

    vector<int> nums2 = {1, 1, 1, 1, 1};
    int k2 = 0;
    cout << "Test Case 2: " << solution.longestEqualSubarray(nums2, k2) << endl;

    vector<int> nums3 = {1, 2, 3, 1, 2, 3};
    int k3 = 2;
    cout << "Test Case 3: " << solution.longestEqualSubarray(nums3, k3) << endl;

    return 0;
}