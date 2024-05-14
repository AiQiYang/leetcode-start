#include <iostream>
#include <string>
#include <unordered_map>
#include <cstdlib>

using namespace std;

class Solution {
public:
    int findPermutationDifference(string s, string t) {
        unordered_map<int, int> umap_t;
        int length = t.size();
        int res = 0;
        for (int i = 0; i < length; i++) {
            umap_t[t[i]] = i;
        }
        for (int i = 0; i < length; i++) {
            int index_t = umap_t[s[i]];
            res += abs(i - index_t);
        }
        return res;
    }
};

int main() {
    Solution solution;
    string s = "great";
    string t = "rgeat";
    int result = solution.findPermutationDifference(s, t);
    cout << "The sum of absolute differences is: " << result << endl;
    return 0;
}