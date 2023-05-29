/**
 * author:CliffLeopard
 * date:2023/05/29
 * time:10:08
 * email:precipiceleopard@gmail.com
 * link:https://leetcode.com/problems/next-permutation/
 * 说明:
 *  1. 最小值为从小到大排列1，2，3，4；最大值为从大到小排列；4，3，2，1
 *  2. 找到第一个从小到大排列的位置。 如果没有则为最大值，直接逆序返回。
 *  3. 如果 1，2，3，4 则为nums[0]=1 的位置开始，nums[0]<nums[1], idx = 0
 *  4. 从idx+1 开始找到最右端的大于nums[idx]的值，肯定存在，至少是idx+1; 位置标记为l
 *  5. 交换nums[idx],nums[l]
 *  6. 将nums，idx后面的所有值取逆
 */

#include<vector>
#include "iostream"
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int idx = -1;
        for(int i = 0; i < n-1; i++) {
            if(nums[i]<nums[i+1]) idx = i;
        }
        // 完全递减
        if(idx == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }
        // 此时 nums[idx] < nums[idx+1]
        int l = idx + 1;
        // 找到最末位置，大于非递减位置
        for(int i = idx + 1; i < n; i++) {
            if(nums[i] > nums[idx]) {
                l = i;
            }
        }
        swap(nums[idx], nums[l]);
        reverse(nums.begin() + 1 + idx, nums.end());
    }
};

int main() {
    Solution solution;
    vector<int> vect = {2,9,4,3};
    solution.nextPermutation(vect);
}