#include <iostream>
#include <vector>
#include <string>
#include <numeric>
using namespace std;

class Solution1 {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        // There are 3 garbage trucks, so we need times 3
        int totalTime = accumulate(travel.begin(), travel.end(), 0) * 3;
        // Calculate the total time to clear all garbage
        for (string gar : garbage) {
            totalTime += gar.size();
        }
        // Subtract the excess distance traveled by each car
        for (char g : {'G', 'P', 'M'}) {
            int index = garbage.size() - 1;
            while (index && garbage[index].find(g) == std::string::npos) {
                totalTime -= travel[index - 1];
                index--;
            }
        }
        return totalTime;
    }
};

class Solution2 {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int times[4]{};
        int travelCost = 0;
        int totalTime = garbage[0].size();
        for (int i = 1; i < garbage.size(); i++) {
            travelCost += travel[i - 1];
            totalTime += garbage[i].size();
            for (char c : garbage[i]) {
                times[c & 3] = travelCost;
            }
        }
        totalTime += accumulate(times, times + 4, 0);
        return totalTime;

    }
};

int main() {
    Solution2 solution;

    // Test Case 1
    vector<string> garbage1 = {"G", "P", "GP", "GG"};
    vector<int> travel1 = {2, 4, 3};
    cout << "Test Case 1: " << solution.garbageCollection(garbage1, travel1) << endl;

    // Test Case 2
    vector<string> garbage2 = {"GP", "PM", "MG"};
    vector<int> travel2 = {15, 25, 35, 45};
    cout << "Test Case 2: " << solution.garbageCollection(garbage2, travel2) << endl;

    // Test Case 3
    vector<string> garbage3 = {"GGG", "PPP", "MMM"};
    vector<int> travel3 = {5, 10, 15, 20};
    cout << "Test Case 3: " << solution.garbageCollection(garbage3, travel3) << endl;

    return 0;
}