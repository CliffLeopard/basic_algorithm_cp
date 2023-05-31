/**
 * author:CliffLeopard
 * date:2023/5/31
 * time:22:11
 * email:precipiceleopard@gmail.com
 * link:https://leetcode.com/problems/search-insert-position/description/
 * 说明: 同样简单二分查找问题
 */

#include "iostream"
#include "vector"
using namespace std;
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left =0,right = nums.size()-1;
        if(right == 0) {
            if(nums[0] >= target)
                return 0;
            else
                return 1;
        }
        int mid = (left + right) /2;
        while(mid >= left) {
            if(target <= nums[left])
                return left;
            if(target == nums[right])
                return  right;
            else if(target > nums[right])
                return right + 1;
            if(nums[mid] == target)
                return  mid;

            if(mid == left) {
                return left+1;
            }

            if(nums[mid] > target) {
                right = mid - 1;
            }

            if(nums[mid] < target) {
                left = mid + 1;
            }
            mid = (left + right)/2;
        }
        return -1;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1,3,5};
    int target = 3;
    int result = s.searchInsert(nums,target);
    cout<<"result: "<<result<<endl;
}