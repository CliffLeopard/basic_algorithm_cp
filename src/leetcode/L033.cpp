/**
 * author:CliffLeopard
 * date:2023/5/30
 * time:19:19
 * email:precipiceleopard@gmail.com
 * link:https://leetcode.com/problems/search-in-rotated-sorted-array/description/
 * 说明: 由于是旋转造成的，两个可能的递增数列不存在交叉。 则分情况分析，按照中位数计算。
 */

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int size = nums.size();
        int left = 0, right = size-1, mid = (left + right) /2;
        while (left <= right) {
            if(target == nums[left]){
                return  left;
            } else if(target == nums[right]) {
                return  right;
            } else if (target ==nums[mid]) {
                return  mid;
            }
            if(nums[mid] > nums[left]) {
                if(target> nums[left] && target < nums[mid]) {
                    right = mid - 1;
                    left = left + 1;
                } else {
                    left = mid + 1;
                    right = right - 1;
                }
            } else {
                if(target > nums[mid] && target < nums[right]) {
                    left = mid + 1;
                    right = right - 1;
                } else {
                    right = mid - 1;
                    left = left + 1;
                }
            }
            mid = (left + right) /2;
        }
        return -1;
    }
};
int main(){
    Solution so;
    vector<int> nums(5);
    nums[0] = 5;
    nums[1] = 1;
    nums[2] = 2;
    nums[3] = 3;
    nums[4] = 4;
    int target = 1;
    int result = so.search(nums,target);
    cout<< result<<endl;
};