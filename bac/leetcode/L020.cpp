/**
 * author:CliffLeopard 
 * date:2019/11/21  
 * time:14:17
 * email:precipiceleopard@gmail.com
 * link:https://leetcode.com/problems/valid-parentheses/
 *
 * 简单的栈操作
 */

#include <iostream>
#include <stack>
#include <map>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> char_stack;
        for (int i = 0; i < s.length(); i++) {
            if (char_stack.empty()) {
                if (amap.find(s[i]) == amap.end()) char_stack.push(s[i]);
                else return false;
            } else {
                if (amap.find(s[i]) == amap.end()) char_stack.push(s[i]);
                else {
                    if (char_stack.top() == amap[s[i]]) char_stack.pop();
                    else return false;
                }
            }
        }
        return char_stack.empty();
    }

private:
    map<char, char> amap = {
            pair<char, char>(')', '('),
            pair<char, char>('}', '{'),
            pair<char, char>(']', '['),
    };
};

int main() {
    string input[] = {
            "()",
            "()[]{}",
            "(]",
            "([)]",
            "{[]}"
    };

    Solution solution;
    for (int i = 0; i < size(input); i++)
        cout << solution.isValid(input[i]) << endl;
}