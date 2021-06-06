/**
 * author:CliffLeopard
 * date:2019/11/12
 * time:19:43
 * email:precipiceleopard@gmail.com
 * link:https://leetcode.com/problems/median-of-two-sorted-arrays/
 */

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

/**
 * 难度:简单
 * 两数组比较排队
 */
class Solution {
public:
    static double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        int n = nums1.size();
        int m = nums2.size();
        bool flag = (n + m) % 2 == 0;
        int sum = 0;
        int i = 0;
        int j = 0;
        int a;

        if (flag) {
            if (m == 0) {
                return (nums1[n / 2 - 1] + nums1[n / 2]) / 2.0;
            } else if (n == 0) {
                return (nums2[m / 2 - 1] + nums2[m / 2]) / 2.0;
            }
        } else {
            if (m == 0) {
                return (double) nums1[n / 2];
            } else if (n == 0) {
                return (double) nums2[m / 2];
            }
        }
        while (i < n || j < m) {
            sum++;
            if (j >= m || (i < n && nums1[i] <= nums2[j])) {
                if (!flag && sum == floor((n + m+0.0) / 2) + 1)
                    return (double) nums1[i];
                else if (flag && sum == (n + m) / 2 + 1)
                    return (a + nums1[i] + 0.0) / 2.0;
                else
                    a = nums1[i];
                i++;
            } else {
                if (!flag && sum == floor((n + m + 0.0) / 2) + 1)
                    return (double) nums2[j];
                else if (flag && sum == (n + m) / 2 + 1)
                    return (a + nums2[j] + 0.0) / 2.0;
                else
                    a = nums2[j];
                j++;
            }
        }
        return 0.0;
    }
};

int main() {
    vector<int> nums1 = vector<int>(1);
    vector<int> nums2 = vector<int>(1);
    nums1[0] = 100001;
//    nums1[1] = 2;
    nums2[0] = 100000;
//    nums2[1] = 4;

    cout << Solution::findMedianSortedArrays(nums1, nums2);
    return 0;
}

