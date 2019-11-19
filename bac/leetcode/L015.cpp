/**
 * author:CliffLeopard 
 * date:2019/11/19  
 * time:14:53
 * email:precipiceleopard@gmail.com
 * link:https://leetcode.com/problems/3sum/
 *
 * 难度:简单
 * 1.排序
 * 2.i=1开始循环，nums[i]作为第一个元素
 * 3.i之后两端开始夹逼。
 * 4.因为结果中不可出现相同数组，夹逼过程中，注意相同值的处理。
 *
 * 此问题算法上没又难度，要注意程序的细节，细节不同效率差别很大。优化循环逻辑。
 */

#include<vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        int n = nums.size();
        vector<vector<int>> result;
        if (n < 3)
            return result;
        sort(nums.begin(), nums.end());
        int i = 0;
        while (i <= n - 3 && nums[i] <= 0) {
            int left_cur = i + 1;
            int right_cur = n - 1;
            while (left_cur < right_cur) {
                if (nums[i] + nums[left_cur] > 0)
                    break;
                int sum = nums[i] + nums[left_cur] + nums[right_cur];
                if (sum > 0) {
                    right_cur--;
                    while (right_cur > left_cur && nums[right_cur] == nums[right_cur + 1])
                        right_cur--;
                } else {
                    if (sum == 0)
                        result.push_back({nums[i], nums[left_cur], nums[right_cur]});
                    left_cur++;
                    while (right_cur > left_cur && nums[left_cur] == nums[left_cur - 1])
                        left_cur++;
                }
            }
            i++;
            while (nums[i] == nums[i - 1]) {
                i++;
                if (i > n - 3 || nums[i] > 0)
                    return result;
            }
        }
        return result;
    }
};

int main() {
//    vector<int> nums = {3, 0, -2, -1, 1, 2};
//    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<int> nums = {1, 1, -2};
    Solution solution;
    vector<vector<int>> result = solution.threeSum(nums);

    vector<vector<int>>::iterator it;
    for (it = result.begin(); it != result.end(); it++) {
        vector<int>::iterator line_it;
        for (line_it = it->begin(); line_it != it->end(); line_it++) {
            cout << *line_it << "  ";
        }
        cout << endl;
    }
}