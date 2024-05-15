#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution {
public:
    int findMinimumTime(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(),  [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        int size = tasks.size();
        vector<int> run(tasks[size - 1][1] + 1);
        int res = 0;
        for (auto task : tasks) {
            int start = task[0], end = task[1], duration = task[2];
            duration -= accumulate(run.begin() + start, run.begin() + end + 1, 0);
            for (int i = end; duration > 0 && i >= start; i--) {
                if (run[i] == 0)  {
                    duration--;
                    run[i] = 1;
                    res++;
                }
            }

        }
        return res;
    }
};

int main() {
    Solution solution;
    std::vector<std::vector<int>> tasks = {{2,3,1}, {4,5,1}, {1,5,2}};
    int result = solution.findMinimumTime(tasks);
    std::cout << "Minimum time needed: " << result << std::endl;
    return 0;
}