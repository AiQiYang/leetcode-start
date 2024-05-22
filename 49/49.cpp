#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> umap;
        for (auto& str : strs) {
            string sortedStr = str;
            sort(sortedStr.begin(), sortedStr.end());
            umap[sortedStr].push_back(str);
        }
        vector<vector<string>> res;
        for (const auto& pair : umap) {
            res.push_back(pair.second);
        }
        return res;
    }
};

int main() {
    Solution solution;

    vector<string> strs1 = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> anagrams1 = solution.groupAnagrams(strs1);
    cout << "Test Case 1:\n";
    for (const auto& group : anagrams1) {
        for (const auto& str : group) {
            cout << str << " ";
        }
        cout << "\n";
    }

    vector<string> strs2 = {""};
    cout << "Test Case 2 (Empty string):\n";
    vector<vector<string>> anagrams2 = solution.groupAnagrams(strs2);
    for (const auto& group : anagrams2) {
        for (const auto& str : group) {
            cout << str << " ";
        }
        cout << "\n";
    }

    vector<string> strs3 = {"a", "a", "a"};
    cout << "Test Case 3 (Single character strings):\n";
    vector<vector<string>> anagrams3 = solution.groupAnagrams(strs3);
    for (const auto& group : anagrams3) {
        for (const auto& str : group) {
            cout << str << " ";
        }
        cout << "\n";
    }

    return 0;
}