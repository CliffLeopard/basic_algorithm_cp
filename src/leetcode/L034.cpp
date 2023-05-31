/**
 * author:CliffLeopard
 * date:2023/5/31
 * time:19:28
 * email:precipiceleopard@gmail.com
 * link:https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
 * 说明: 没有很难，注意边界值判断。 而分查找变体。
 */
#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int> &nums, int target) {
        vector<int> result = {-1, -1};
        int left = 0;
        int right = nums.size() - 1;

        if (right == 0) {
            if (target == nums[right]) {
                result = {0, 0};
            }
        }

        int mid = (left + right) / 2;
        while (left < right) {
            if (target == nums[left] && result[0] == -1) {
                result[0] = left;
            }

            if (target == nums[right] && result[1] == -1) {
                result[1] = right;
            }

            if (left >= mid) {
                break;
            }

            if (target == nums[mid]) {
                if (result[0] == -1)
                    result[0] = searchLeft(nums, left + 1, mid, target);
                if (result[1] == -1) {
                    result[1] = searchRight(nums, mid, right - 1, target);
                }
                break;
            } else {
                if (nums[mid] < target) {
                    left = mid + 1;
                }

                if (nums[mid] > target) {
                    right = mid - 1;
                }
                mid = (left + right) / 2;
            }
        }

        if (result[0] == -1 && result[1] != -1) {
            result[0] = result[1];
        }

        if (result[1] == -1 && result[0] != -1) {
            result[1] = result[0];
        }
        return result;
    }

    int searchLeft(vector<int> &nums, int left, int right, int target) {
        int mid = (left + right) / 2;
        while (mid >= left) {
            if (nums[left] == target)
                return left;
            if (mid == left) {
                return right;
            }

            if (nums[mid] == target) {
                right = mid;
                if (mid >= 1 && nums[mid - 1] != target) {
                    return mid;
                }
            } else {
                left = mid + 1;
            }
            mid = (left + right) / 2;
        }
        return -1;
    }

    int searchRight(vector<int> &nums, int left, int right, int target) {
        int mid = (left + right) / 2;
        while (mid >= left) {
            if (nums[right] == target)
                return right;
            if (mid == left) {
                return left;
            }
            if (nums[mid] == target) {
                left = mid;
                if (mid < right && nums[mid + 1] != target)
                    return mid;
            } else {
                right = mid -1;
            }
            mid = (left + right) /2 ;
        }
        return -1;
    }
};

int main() {
    Solution s;
    vector<int> nums = {0,0,1,1,1,2,4,4,4,4,5,5,5,6,8,8,9,9,10,10,10};
//    vector<int> nums = {5,7,7,8,8,10};
//    vector<int> nums = {};
//    vector<int> nums = {3,1};
    int target = 8;
//    int target = 6;
//    int target = 0;
    vector<int> result = s.searchRange(nums, target);
    cout << "输出结果: ";
    for (auto index: result) {
        cout << index << "  ";
    }
    cout << endl;
    return 0;
}