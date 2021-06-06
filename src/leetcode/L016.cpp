/**
 * author:CliffLeopard 
 * date:2019/11/20  
 * time:12:57
 * email:precipiceleopard@gmail.com
 * link:https://leetcode.com/problems/3sum-closest/
 */

#include <iostream>
#include <vector>

using namespace std;

/**
 * 类似15
 * 找到一位，中间夹逼。
 */
class Solution {
public:
    static int threeSumClosest(vector<int> &nums, int target) {
        int min = INT32_MAX;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int result, sum;
        for (int i = 0; i < n; i++) {
            int now = nums[i];
            int left = i + 1;
            int right = n - 1;
            while (left < right) {
                sum = now + nums[left] + nums[right];
                if (sum == target)
                    return target;
                if (abs(sum - target) < min) {
                    min = abs(sum - target);
                    result = sum;
                }
                if (sum > target) {
                    right--;
                } else {
                    left++;
                }
            }
        }
        return result;
    }
};

int main() {
    vector<int> nums = {-1, 2, 1, -4};
    int target = 1;
    cout << Solution::threeSumClosest(nums, target) << endl;
}