#include <vector>
#include <unordered_set>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> n1_set(nums1.begin(), nums1.end());
        unordered_set<int> n2_set(nums2.begin(), nums2.end());

        vector<int> res(2, 0);

        for (const auto& elem : n1_set) {
        cout << elem << " ";
        }
        cout << endl;
        for (const auto& elem : n2_set) {
        cout << elem << " ";
        }
        cout << endl;
        for (const auto& num : nums1) {
            if (n2_set.find(num) != n2_set.end()) {
                res[0]++;
            }
        }

        for (const auto& num : nums2) {
            if (n1_set.find(num) != n1_set.end()) {
                res[1]++;
            }
        }

        return res;
    }
};
void printVector(const vector<int>& vec) {
    for (int val : vec) {
        cout << val << " ";
    }
    cout << endl;
}

int main() {
    Solution sol;

    vector<int> nums1_1 = {3, 2, 2};
    vector<int> nums2_1 = {1, 2};
    vector<int> result_1 = sol.findIntersectionValues(nums1_1, nums2_1);
    printVector(result_1);  // Output should be [2, 2]

    vector<int> nums1_2 = {4, 9, 5};
    vector<int> nums2_2 = {9, 4, 9, 8, 4};
    vector<int> result_2 = sol.findIntersectionValues(nums1_2, nums2_2);
    printVector(result_2);  // Output should be [2, 2]

    vector<int> nums1_3 = {1, 2, 3, 4, 5};
    vector<int> nums2_3 = {6, 7, 8, 9, 10};
    vector<int> result_3 = sol.findIntersectionValues(nums1_3, nums2_3);
    printVector(result_3);  // Output should be [0, 0]

    vector<int> nums1_4 = {};
    vector<int> nums2_4 = {1, 2, 3};
    vector<int> result_4 = sol.findIntersectionValues(nums1_4, nums2_4);
    printVector(result_4);  // Output should be [0, 0]

    vector<int> nums1_5 = {1, 1, 1, 1};
    vector<int> nums2_5 = {1, 1};
    vector<int> result_5 = sol.findIntersectionValues(nums1_5, nums2_5);
    printVector(result_5);  // Output should be [2, 4]

    return 0;
}