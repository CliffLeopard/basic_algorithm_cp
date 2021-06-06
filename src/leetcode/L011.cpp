/**
 * author:CliffLeopard 
 * date:2019/11/18  
 * time:14:33
 * email:precipiceleopard@gmail.com
 * link: https://leetcode.com/problems/container-with-most-water/
 */

#include <vector>
#include<iostream>

using namespace std;


/**
 * 从两端向中间挤压
 * 这个解法利用了插入的隔板间距相等。使用较高的隔板和远处的最高的隔板计算，这是因为高度会带来大的差值，距离只是逐次减少。
 */
class Solution {
public:
    static int maxArea(vector<int> &height) {
        int result = 0;
        int l = 0, r = height.size() - 1;
        while (l < r) {
            result = max(result, min(height[l], height[r]) * (r - l));
            if (height[l] < height[r]) {
                l++;
            } else
                r--;
        }
        return result;
    }
};

/**
 * 本质上和上面解法相同，理论上赋值减少效率应该高些，但实际不是这样，应该是因为增加了判断。
 */
class Solution2 {
public:
    static int maxArea(vector<int> &height) {
        int result = 0;
        int l = 0, r = height.size() - 1;
        while (l < r) {
            int minHeight = min(height[l], height[r]);
            result = max(result, minHeight * (r - l));
            while (l < r && height[l] <= minHeight) {
                l++;
            }
            while (l < r && height[r] <= minHeight)
                r--;
        }
        return result;
    }
};

/**
 * 最笨的办法，循环 O(n^2)的效率
 */
class Solution0 {
public:
    static int maxArea(vector<int> &height) {
        int n = height.size();
        int temp = 0;
        int maxAr = 0;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                int area = (j - i) * min(height[j], height[i]);
                if (area > maxAr)
                    maxAr = area;
            }
        }
        return maxAr;
    }
};

int main() {
    vector<int> area = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << Solution2::maxArea(area) << endl;
    return 0;
}