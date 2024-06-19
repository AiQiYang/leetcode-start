#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        unordered_map<int, int> map;
        set<vector<int>> res;
        int size = nums.size();
        for (int i = 0; i < size; i++) {
            map[nums[i]] = i;
        }
        for (int i = 0; i < size - 1; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            for (int j = i + 1; j < size; j++) {
                if (nums[j] > i + 1 && nums[j] == nums[j - 1]) continue;
                auto it = map.find(0 - nums[i] - nums[j]);
                if (it != map.end() && it->second != i && it->second != j && i != j) {
                    vector<int> sorted_vec = {nums[it->second], nums[i], nums[j]};
                    sort(sorted_vec.begin(), sorted_vec.end());
                    res.insert(sorted_vec);
                }
            }
        }
        vector<vector<int>> vec;
        vec.reserve(res.size());

        copy(res.begin(), res.end(), back_inserter(vec));
        return vec;
    }
};

void testThreeSum() {
    Solution sol;

    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> expected = {{-1, -1, 2}, {-1, 0, 1}};
    vector<vector<int>> result = sol.threeSum(nums);

    std::sort(expected.begin(), expected.end());
    std::sort(result.begin(), result.end());
    if (result == expected) {
        std::cout << "Test case passed.\n";
    } else {
        std::cout << "Test case failed.\n";
    }
}

int main() {
    testThreeSum();
    return 0;
}
