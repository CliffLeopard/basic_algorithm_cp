/**
 * author:CliffLeopard 
 * date:2019/11/27  
 * time:01:06
 * email:precipiceleopard@gmail.com
 * link: https://leetcode.com/problems/remove-element/description/
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int valIndex = nums.size() - 1;
        int beginIndex = 0;
        while (valIndex >= beginIndex) {
            while (valIndex >= beginIndex && nums[valIndex] == val) valIndex--;
            while (beginIndex <= valIndex && nums[beginIndex] != val) beginIndex++;
            if (valIndex > beginIndex) {
                nums[valIndex] += nums[beginIndex];
                nums[beginIndex] = nums[valIndex] - nums[beginIndex];
                nums[valIndex] = nums[valIndex] - nums[beginIndex];
            }
        }
        return valIndex + 1;
    }
};