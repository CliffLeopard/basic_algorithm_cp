/**
 * author:CliffLeopard
 * date:2019/11/10
 * time:15:23
 * email:precipiceleopard@gmail.com
 * link:https://leetcode.com/problems/two-sum/
 */

#include <iostream>
#include <vector>

using namespace std;

/**
 * 难度:简单
 * 简单二次循环，相加问题
 */
class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        vector<int> result(2);
        int len = nums.size();
        int i = 0;
        while (i < len) {
            int j = i + 1;
            while (j < len) {
                if (nums[i] + nums[j] == target) {
                    result[0] = i;
                    result[1] = j;
                    return result;
                }
                j++;
            }
            i++;
        }
        return result;
    }
};

int main() {
    Solution solution;
    vector<int> nums(4);
    nums[0] = 2;
    nums[1] = 7;
    nums[2] = 11;
    nums[3] = 15;
    int target = 26;

    vector result = solution.twoSum(nums, target);
    cout << result[0] << "  " << result[1] << endl;
    return 0;
}

