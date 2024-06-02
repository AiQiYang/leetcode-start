#include <iostream>
#include <vector>
#include <unordered_set>
#include <cassert>
using namespace std;

class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_set<int> type(candyType.begin(), candyType.end());
        int candies = candyType.size() / 2;
        int types = type.size();
        return min(candies, types);
    }
};

int main() {
    Solution solution;
    
    vector<int> candyType1 = {1, 1, 2, 2, 3, 3};
    int expected1 = 3;
    assert(solution.distributeCandies(candyType1) == expected1);
    
    vector<int> candyType2 = {1, 1, 2, 3};
    int expected2 = 2;
    assert(solution.distributeCandies(candyType2) == expected2);
    
    vector<int> candyType3 = {1, 1, 1};
    int expected3 = 1;
    assert(solution.distributeCandies(candyType3) == expected3);
    
    std::cout << "All test cases passed." << std::endl;

    return 0;
}