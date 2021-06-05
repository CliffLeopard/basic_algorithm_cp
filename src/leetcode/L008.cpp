/**
 * author:CliffLeopard 
 * date:2019/11/19  
 * time:06:47
 * email:precipiceleopard@gmail.com
 * link:https://leetcode.com/problems/string-to-integer-atoi/
 *
 * 简单，细节很重要
 * 1.空字符串
 * 2.0开头
 * 3.string的最大长度需用unsigned long表示
 */

#include <iostream>
#include <sstream>

using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        if (str.empty()) return 0;
        int n = str.length();
        int begin = -1;
        int end = n;
        bool positive = true;
        int result;
        for (int i = 0; i < str.length(); i++) {
            if (begin == -1) {
                if (isNum(str[i])) {
                    begin = i;
                } else if (str[i] == '-' || str[i] == '+') {
                    if (i < n - 1 && isNum(str[i + 1])) {
                        begin = i + 1;
                        positive = str[i] == '+';
                    } else {
                        return 0;
                    }
                } else if (str[i] != ' ' && str[i] != '0') {
                    return 0;
                }
            } else if (!isNum(str[i])) {
                end = i;
                break;
            }

        }
        if (begin == -1)
            return 0;
        string num = str.substr(begin, end - begin);
        unsigned long k = num.find_first_not_of('0');
        if (k == string::npos) return 0;
        if (k > 0) num = num.substr(k, num.length());
        if (num.length() > 10)
            return positive ? INT32_MAX : INT32_MIN;
        if (num.length() == 10) {
            string max = to_string(INT32_MAX);
            for (int i = 0; i < 10; i++) {
                if (i == 9 && !positive) {
                    if (num[i] - '0' > 8)
                        return INT32_MIN;
                }
                if (num[i] > max[i])
                    return positive ? INT32_MAX : INT32_MIN;
                else if (num[i] < max[i])
                    break;
            }
        }
        if (!positive)
            num = '-' + num;
        stringstream geek(num);
        geek >> result;
        return result;

    }

private:
    bool isNum(char ch) {
        if (ch - '0' >= 0 && ch - '9' <= 0)
            return true;
        else
            return false;
    }
};

int main() {
    string input[] = {
            "  +42 kk  kk",
            "   -42",
            "   +4193 with words",
            "words and 987",
            "words and +987",
            "-91283472332",
            "-",
            "  0000000000012345678",
            "  -00000000012345678",
            " -012",
            " ",
            "-2147483647",
            "-10",
            "1095502006p8"
    };
    Solution solution;
    for (int i = 0; i < size(input); i++)
        cout << solution.myAtoi(input[i]) << endl;
    return 0;
}




