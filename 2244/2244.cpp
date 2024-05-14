#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> umap;
        for (int i = 0; i < tasks.size(); i++) {
            umap[tasks[i]]++;
        }
        int res = 0;
        for (auto [_, fre] : umap) {
            // cout << "fre" << fre << " with num: " << num << endl;
            if (fre == 1) {
                return -1;
            } else if (fre % 3 == 0) {
                res += fre / 3;
            } else {
                res += fre / 3 + 1;
            }
        }
        return res;
    }
};

int main() {
    Solution solution;
    vector<int> tasks = {2,2,3,3,2,4,4,4,4,4};
    int result = solution.minimumRounds(tasks);
    if (result != -1) {
        cout << "Minimum rounds needed: " << result << endl;
    } else {
        cout << "It is not possible to complete the tasks following the given rules." << endl;
    }
    return 0;
}