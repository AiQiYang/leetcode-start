#include <iostream>
#include <cassert>
#include <algorithm> // 用于 std::min 和 std::max 函数
using namespace std;

class Solution {
public:
    int distributeCandies(int n, int limit) {
        int res = 0;
        for (int i = 0; i <= limit; i++) {
            if (n - i > limit * 2) {
                continue;
            }
            res += min(limit, n - i) - max(0, n - i - limit) + 1;
        }
        return res;
    }
};

int main() {
    Solution solution;
    
    int n1 = 10, limit1 = 2;
    assert(solution.distributeCandies(n1, limit1) == 0);
    
    int n2 = 5, limit2 = 3;
    assert(solution.distributeCandies(n2, limit2) == 12);
    
    int n3 = 7, limit3 = 3;
    assert(solution.distributeCandies(n3, limit3) == 6);

    cout << "All test cases passed!" << endl;

    return 0;
}