#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int, int>> jobs;
        for (int i = 0; i < difficulty.size(); i++) {
            jobs.push_back(make_pair(difficulty[i], profit[i]));
        }
        
        sort(jobs.begin(), jobs.end());
        sort(worker.begin(), worker.end());
        
        int res = 0, jobsIndex = 0, maxProfit = 0;
        for (auto w : worker) {
            while (jobsIndex < jobs.size() && w >= jobs[jobsIndex].first) {
                maxProfit = max(maxProfit, jobs[jobsIndex++].second);
            }
            res += maxProfit;
        }
        return res;
    }
};

int main() {
    Solution solution;

    vector<int> difficulty1 = {2,4,6,8,10};
    vector<int> profit1 = {10,20,30,40,50};
    vector<int> worker1 = {4, 5, 6, 7};
    cout << "Test Case 1: " << solution.maxProfitAssignment(difficulty1, profit1, worker1) << endl;

    vector<int> difficulty2 = {1, 3, 5, 7};
    vector<int> profit2 = {1, 3, 5, 7};
    vector<int> worker2 = {1, 2, 3, 4, 5, 6, 7};
    cout << "Test Case 2: " << solution.maxProfitAssignment(difficulty2, profit2, worker2) << endl;

    return 0;
}