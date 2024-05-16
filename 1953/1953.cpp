#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long numberOfWeeks(vector<int>& milestones) {
        long long maxTasks = *max_element(milestones.begin(), milestones.end());
        long long rest = accumulate(milestones.begin(), milestones.end(), 0LL) - maxTasks;
        if (maxTasks > rest + 1) {
            return rest * 2 + 1;
        }
        return maxTasks + rest;
    }
};

int main() {
    Solution solution;

    vector<int> milestones1 = {1, 2, 3, 4, 5};
    cout << "Test Case 1: " << solution.numberOfWeeks(milestones1) << endl;

    vector<int> milestones2 = {2, 2, 2};
    cout << "Test Case 2: " << solution.numberOfWeeks(milestones2) << endl;
    
    vector<int> milestones3 = {5, 5, 5};
    cout << "Test Case 3: " << solution.numberOfWeeks(milestones3) << endl;
}