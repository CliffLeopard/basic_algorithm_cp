/**
 * author:CliffLeopard 
 * date:2019/11/21  
 * time:20:45
 * email:precipiceleopard@gmail.com
 * link:https://leetcode.com/problems/generate-parentheses/
 * 难度:简单
 * 递归
 * 对这个问题我走了一些弯路，就是对合法性的验证问题想的太复杂了，在仅仅由'(',')'构成的字符串中
 * '('=1,')'=-1 只要从左至右的整个过程中，sum>=0,并最终sum==0则合法。
 */
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        char *element = new char[2 * n];
        if (n == 0)
            return result;
        generate(result, element, n, 0, 0);
        return result;
    }

private:
    void generate(vector<string> &result, char *element, int n, int left, int right) {
        if (left == n && right == n) {
//           这里特别shit,leetCode不支持char* 转string的构造函数。
            string res = "";
            for (int i = 0; i < 2 * n; i++) {
                res.push_back(element[i]);
            }
            result.push_back(res);
        } else if (right <= left) {
            if (left < n) {
                element[left + right] = '(';
                generate(result, element, n, left + 1, right);
            }
            if (right < n) {
                element[left + right] = ')';
                generate(result, element, n, left, right + 1);
            }
        }
    }
};

int main() {
    Solution solution;
    vector<string> result = solution.generateParenthesis(3);
    vector<string>::iterator iterator;
    for (iterator = result.begin(); iterator != result.end(); iterator++)
        cout << *iterator << endl;
}