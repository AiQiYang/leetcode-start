#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int size = grid[0].size();
        vector<int> rec(size*size+1, 0);
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                rec[grid[i][j]]++;
            }
        }
        vector<int> res(2);
        for (int i = 0; i < rec.size(); i++) {
            if (rec[i] == 2) {
                res[0] = i;
            }
            if (rec[i] == 0) {
                res[1] = i;
            }
        }
        return res;
    }
};

int main() {

    Solution solution;

    vector<vector<int>> grid1 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 5}};
    vector<int> result1 = solution.findMissingAndRepeatedValues(grid1);
    assert(result1[0] == 5 && result1[1] == 9);

    vector<vector<int>> grid2 = {{1, 2, 3}, {3, 5, 6}, {7, 8, 9}};
    vector<int> result2 = solution.findMissingAndRepeatedValues(grid2);
    assert(result2[0] == 3 && result2[1] == 4);

    vector<vector<int>> grid3 = {{1, 2, 3}, {2, 4, 5}, {6, 7, 8}};
    vector<int> result3 = solution.findMissingAndRepeatedValues(grid3);
    assert(result3[0] == 2 && result3[1] == 9);

    cout << "All tests passed!" << endl;
    
    return 0;
}