#include <iostream>
#include <vector>
#include <unordered_map>
#include <deque>

using namespace std;

class Solution {
public:
    int findWinningPlayer(vector<int>& skills, int k) {
        unordered_map<int, int> umap;
        for (int i = 0; i < skills.size(); i++) {
            umap[skills[i]] = i;
        }

        int index = 1;
        int count = 0;
        deque<int> deq(skills.begin(), skills.end());
        while (count < k) {
            index++;
            int x = deq.front();
            deq.pop_front();
            int y = deq.front();
            deq.pop_front();
            if (index > skills.size()) {
                deq.push_front(x);
                break;
            } else if (x > y) {
                deq.push_front(x);
                deq.push_back(y);
                count++;
            } else {
                deq.push_front(y);
                deq.push_back(x);
                count = 1;
            }
        }
        return umap[deq.front()];
    }
};

int main() {
    Solution solution;
    vector<int> skills;
    int k;

    // Test case 1
    skills = {2, 5, 4};
    k = 3;
    cout << "Winning player index: " << solution.findWinningPlayer(skills, k) << endl; // Expected output: index of player with skill 5

    // // Test case 2
    // skills = {1, 3, 2, 4};
    // k = 1;
    // cout << "Winning player index: " << solution.findWinningPlayer(skills, k) << endl; // Expected output: index of player with skill 3

    // // Test case 3
    // skills = {6, 1, 5, 2, 3, 4};
    // k = 3;
    // cout << "Winning player index: " << solution.findWinningPlayer(skills, k) << endl; // Expected output: index of player with skill 6

    // // Test case 4
    // skills = {3, 2, 1};
    // k = 5;
    // cout << "Winning player index: " << solution.findWinningPlayer(skills, k) << endl; // Expected output: index of player with skill 3

    return 0;
}
