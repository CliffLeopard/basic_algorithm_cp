/**
 * author:CliffLeopard
 * date:2023/5/30
 * time:19:19
 * email:precipiceleopard@gmail.com
 * link:https://leetcode.com/problems/longest-valid-parentheses/description/
 * 说明:
 * 使用栈来记录（的position， 每次遇到)则出栈。
 * 出栈后为空，说明前面没有（，记录一下当前位置
 * 出栈后不为空，则已经成功一对，记录一下位置长度。与max_len进行比较
 */
#include<iostream>
#include "stack"

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1);
        int n = s.size();
        int max_len = 0;
        for (int i=0; i< n;i++) {
            char  character = s[i];
            if (character == '(') {
                st.push(i);
            } else {
                st.pop();
                if(st.empty()) {
                    st.push(i);
                } else {
                    max_len = max(i - st.top(), max_len);
                }

            }
        }
        return max_len;
    }
};

int main() {
    Solution s;
    int result = s.longestValidParentheses("()");
    cout << "result=" << result << endl;
    return 0;
}