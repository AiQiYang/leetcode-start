#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <queue>
#include <set>
#include <algorithm>
#include <cassert>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dictionary = {wordList.begin(), wordList.end()};

        vector<vector<string>> res;
        if (dictionary.find(endWord) == dictionary.end()) {
            return res;
        }

        dictionary.erase(beginWord);
        queue<string> que;
        que.push(beginWord);
        unordered_map<string, set<string>> from = {{beginWord, {}}};
        unordered_map<string, int> steps = {{beginWord, 0}};
        int step = 0;
        bool found = false;

        while (!que.empty()) {
            int size = que.size();
            step++;
            for (int i = 0; i < size; i++) {
                string current = que.front();
                que.pop();
                int curSize = current.size();
                for (int j = 0; j < curSize; j++) {
                    for (char c = 'a'; c <= 'z'; c++) {
                        string nextWord = current;
                        nextWord[j] = c;
                        if (steps[nextWord] == step) {
                            from[nextWord].insert(current);
                        }
                        if (nextWord == current) continue;
                        
                        if (dictionary.find(nextWord) == dictionary.end()) continue;

                        dictionary.erase(nextWord);
                        que.push(nextWord);
                        from[nextWord].insert(current);
                        steps[nextWord] = step;
                        if (nextWord == endWord) {
                            found = true;
                        }
                    }
                }
            }
            if (found) break;
        }
    //     for (const auto& pair : from) {
    //     std::cout << pair.first << " -> ";
    //     std::cout << "{";
    //     for (auto it = pair.second.begin(); it != pair.second.end(); ) {
    //         std::cout << *it;
    //         if (++it != pair.second.end()) {
    //             std::cout << ", ";
    //         }
    //     }
    //     std::cout << "}";
    //     std::cout << std::endl;
    // }

        if (found) {
            vector<string> path = {endWord};
            backtracking(res, endWord, beginWord, from, path);
        }
        return res;
    }

    void backtracking(vector<vector<string>> &res, const string &node, string &startWord, unordered_map<string, set<string>> &from, vector<string> &path) {
        if (from[node].empty()) {
            res.push_back({path.rbegin(), path.rend()});
            return;
        }
        for (const string& parent : from[node]) {
            path.push_back(parent);
            backtracking(res, parent, startWord, from, path);
            path.pop_back();
        }
    }
};

int main() {
    Solution solution;
    
    // 测试用例 1
    vector<string> wordList1 = {"hot","dot","dog","lot","log","cog"};
    string beginWord1 = "hit";
    string endWord1 = "cog";
    vector<vector<string>> expected1 = {{"hit", "hot", "dot", "dog", "cog"},
                                        {"hit", "hot", "lot", "log", "cog"}};
    vector<vector<string>> result1 = solution.findLadders(beginWord1, endWord1, wordList1);
    for (auto& v : result1) {
        for (auto& s : v) {
            cout << s << ", ";
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}