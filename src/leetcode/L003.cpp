/**
 * author:CliffLeopard
 * date:2019/11/10
 * time:18:35
 * email:precipiceleopard@gmail.com
 * link:https://leetcode.com/problems/longest-substring-without-repeating-characters/
 */

#include <iostream>

using namespace std;

/**
 * 难度:简单
 * 最大不循环子串问题
 * 窗口滑动问题，找到最大不循环子串的开始和结束指针
 * sp从0开始，ep从1开始，寻找[sp,ep)范围内与s[ep]相同的字符
 *   如果没找到，则显然以sp为起点的字串加一。
 *   否则以sp为起点不循环子串终结。比较并记录length。sp移动到找到的相同位置，继续进行ep指针下游。
 */
class Solution {
public:
    static int lengthOfLongestSubstring(string s) {
        if (empty(s))
            return 0;
        else if (size(s) == 1)
            return 1;
        int maxLength = 1;
        int len = size(s);
        int sp = 0;
        int ep = 1;
        while (ep < len) {
            int lp = s.substr(sp, ep - sp).find(s[ep]);
            if (lp != s.npos) {
                maxLength = max(maxLength, ep - sp);
                sp = sp + lp + 1;
            }
            ep++;
        }
        return max(maxLength, ep - sp);
    }
};

int main() {
    cout << Solution::lengthOfLongestSubstring("abcecbccbae");
    return 0;
}
