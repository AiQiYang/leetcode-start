#include <iostream>
#include <string>
#include <cassert> 
using namespace std;

class Solution {
public:
    long long minimumSteps(string s) {
        int s_size = s.size();
        long long steps = 0;
        int right = s_size - 1;
        for (int i = s_size - 1; i >= 0; i--) {
            if (s[i] == '1') {
                steps += right - i;
                right--;
            }
        }
        return steps;
    }
};

int main() {
    Solution solution;
    
    string test1 = "1111";
    string test2 = "0110";
    string test3 = "0101";
    string test4 = "101"; 

    assert(solution.minimumSteps(test1) == 0);
    assert(solution.minimumSteps(test2) == 2);
    assert(solution.minimumSteps(test3) == 1);
    assert(solution.minimumSteps(test4) == 1);

    cout << "All tests passed!" << endl;

    return 0;
}