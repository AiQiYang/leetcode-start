#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> res(num_people, 0);
        int index = 0;
        int candy = 1;
        while (candies) {
            res[index % num_people] += min(candy, candies);
            candies -= min(candy, candies);
            index++;
            candy++;
        }
        return res;
    }
};

int main() {
    Solution solution;
    
    int candies = 7;
    int num_people = 4;

    std::vector<int> result = solution.distributeCandies(candies, num_people);

    std::cout << "Candies distribution: ";
    for (int i = 0; i < result.size(); i++) {
        std::cout << result[i] << " ";
    }
    std::cout << std::endl;
    
    return 0;
}