#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>

using namespace std;

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

void testTrap() {
    Solution sol;

    // Test case 1
    vector<int> height1 = {0,1,0,2,1,0,1,3,2,1,2,1};
    int result1 = sol.trap(height1);
    assert(result1 == 6);
    cout << "Test case 1 passed!" << endl;

    // Test case 2
    vector<int> height2 = {4,2,0,3,2,5};
    int result2 = sol.trap(height2);
    assert(result2 == 9);
    cout << "Test case 2 passed!" << endl;

    // Test case 3
    vector<int> height3 = {1,2,3,4,5};
    int result3 = sol.trap(height3);
    assert(result3 == 0);
    cout << "Test case 3 passed!" << endl;

    // Test case 4
    vector<int> height4 = {5,4,3,2,1};
    int result4 = sol.trap(height4);
    assert(result4 == 0);
    cout << "Test case 4 passed!" << endl;

    // Test case 5
    vector<int> height5 = {1,0,2,1,0,1,3,2,1,2,1};
    int result5 = sol.trap(height5);
    assert(result5 == 6);
    cout << "Test case 5 passed!" << endl;
}

int main() {
    testTrap();
    cout << "All test cases passed!" << endl;
    return 0;
}
