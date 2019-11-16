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
 * 窗口滑动问题，找到最大不循环子串的开始和结指针
 */
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
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
    Solution solution;
    cout << solution.lengthOfLongestSubstring("abcabccbae");
    return 0;
}
