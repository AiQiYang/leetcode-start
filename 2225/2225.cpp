#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, int> umap;
        vector<int> ans0;
        vector<int> ans1;
        for (auto match : matches) {
            if (umap.find(match[0]) == umap.end()) {
                umap[match[0]] = 0;
            }
            umap[match[1]]++;
        }
        
        for (auto it = umap.begin(); it != umap.end(); it++) {
            if (it->second == 0) {
                ans0.push_back(it->first);
            } else if (it->second == 1) {
                ans1.push_back(it->first);
            }
        }
        vector<vector<int>> res;
        sort(ans0.begin(), ans0.end());
        sort(ans1.begin(), ans1.end());
        res.push_back(ans0);
        res.push_back(ans1);
        return res;
    }
};

int main() {
    Solution solution;

    vector<vector<int>> matches1 = {{1, 2}, {2, 3}, {3, 4}};
    vector<vector<int>> winners1 = solution.findWinners(matches1);
    cout << "Test Case 1:\n";
    for (const auto& winner : winners1) {
        for (int player : winner) {
            cout << player << " ";
        }
        cout << endl;
    }

    vector<vector<int>> matches2 = {{1, 1}, {2, 2}, {3, 3}};
    vector<vector<int>> winners2 = solution.findWinners(matches2);
    cout << "Test Case 2:\n";
    for (const auto& winner : winners2) {
        for (int player : winner) {
            cout << player << " ";
        }
        cout << endl;
    }

    return 0;
}