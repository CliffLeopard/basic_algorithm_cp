/**
 * author:CliffLeopard 
 * date:2019/11/17  
 * time:04:18
 * email:precipiceleopard@gmail.com
 * link:https://leetcode.com/problems/regular-expression-matching/
 *
 * 典型可以通过动态规划解决的问题
 * 如果用dp[i][j] 表示s[0,i] p[0,j]闭区间内的匹配状况
 *
 * p[j] !='*'
 *    dp[i][j] = dp[i- 1][j-1] && (s[i] == p[j] || p[j] == '.');
 * p[j] =='*'
 *      1. dp[i][j] = dp[i][j-2]                                               *代表0次
 *         比如s=abc p = ad*bc     p[j] == '*' 时，*代表0次，相当于消掉d*
 *              dp[0][0]=true;
 *              dp[0][1]=false;
 *              dp[1][0]=false;
 *         i=1;j=2 时，p[j] == '*'
 *              dp[1][2] = dp[1][0] = false;
 *         i=2;j=2 时，p[j] == '*'
 *              dp[2][2] = dp[2][0] = false;
 *      2. dp[i][j] = dp[i-1][j] && (s[i] == p[j-1] || p[j-1] == '.')          *代表一次或者多次
 *          比如 s1 = abbc  p1 =  ab*c  i=2 j=2 dp[2][2] = dp[1][2] && (...)
 *          比如 s1 = abec  p1 =  ab*c  i=2 j=2 dp[2][2] = dp[1][2] && (...)
 *
 *两种情况只要其中一种成立则dp[i][j] = true;
 *
 * 但是
 *   涉及到0初始化问题，我们使用dp[i][j]表示 s[0,i), p[0,j) 左闭右开区间内的匹配情况。则发生变化
 *  dp[0][0] = true;
 * p[j-1] !='*'
 *    dp[i][j] = dp[i- 1][j-1] && (s[i-1] == p[j-1] || p[j-1] == '.');
 * p[j-1] =='*'
 *      1. dp[i][j] = dp[i][j-2]                                                 *代表0次
 *      2. dp[i][j] = dp[i-1][j] && (s[i-1] == p[j-2] || p[j-2] == '.')          *代表一次或者多次
 */


#include <iostream>
#include <string>
#include<vector>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;
        for (int i = 0; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (p[j - 1] == '*') {
                    dp[i][j] = (j > 1 && dp[i][j - 2]) ||
                               (i && j > 1 && dp[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.'));
                } else {
                    dp[i][j] = i && dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
                }
            }
        }
        return dp[m][n];
    }
};

class Solution2 {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<bool> pre(n + 1, false), cur(n + 1, false);
        cur[0] = true;
        for (int i = 0; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (p[j - 1] == '*') {
                    cur[j] = cur[j - 2] || (i && pre[j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.'));
                } else {
                    cur[j] = i && pre[j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
                }
            }
            fill(pre.begin(), pre.end(), false);
            swap(pre, cur);
        }
        return pre[n];
    }
};


/**
 * 仔细观察程序
 *     对于s的向前判断只到i-1,则cur[j]在没有被再次赋值之前，存储的便是i=i-1时cur[j]的值。
 *     则发现不需要二维数组这么大的空间，因为状态转移的时候涉及到了极少的变量。
 *     只需要观察匹配字符光标的移动即可，
 */
class Solution3 {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<bool> cur(n + 1, false);
        for (int i = 0; i <= m; i++) {
            bool pre = cur[0];
            cur[0] = !i;
            for (int j = 1; j <= n; j++) {
                bool temp = cur[j];
                if (p[j - 1] == '*') {
                    cur[j] = j>2 && (cur[j - 2] || (i && cur[j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.')));
                } else {
                    cur[j] = i && pre && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
                }
                pre = temp;
            }
        }
        return cur[n];
    }
};

class Solution0 {
public:
    bool isMatch(string s, string p) {
        int s_len = s.length(), p_len = p.length();
        bool **match = new bool *[s_len + 1];
        for (int i = 0; i <= s_len; i++) {
            match[i] = new bool[p_len + 1]{false};
        }
        match[0][0] = true;
        for (int i = 0; i <= s_len; i++) {
            for (int j = 1; j <= p_len; j++) {
                if (p[j - 1] == '*') {
                    match[i][j] = (j > 1 && match[i][j - 2]) ||
                                  (i && j > 1 && match[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.'));
                } else {
                    match[i][j] = i && match[i - 1][j - 1] && (
                            p[j - 1] == s[i - 1] || p[j - 1] == '.'
                    );
                }
            }
        }
        return match[s_len][p_len];
    }
};

int main() {

    string s[] = {
            "a",
            "aa",
            "aa",
            "ab",
            "mississippi",
            "aaa",
            "aaa",
            "aaa",
            "aaa",
            "ab",
            "a",
            "",
            "aab",
            "abc",
            "fas",
            "faadfas",
            "ab",
            "aaba",
            "aasdfasdfasdfasdfas",
            "abcdede",
            "",
            "ac"
    };
    string p[] = {
            "a",
            "a",
            "a*",
            ".b",
            "mis*is*ip*.",
            "a*a",
            "ac*b*a*",
            "ab*a",
            "ab*a*c*a",
            ".*",
            ".*.a*",
            ".*",
            "c*aab*",
            ".*.",
            "f.*s",
            "f.*aadf.*s",
            ".*c",
            "ab*a*c*a",
            "aasdf.*asdf.*asdf.*asdf.*s",
            "ab.*de",
            "",
            "*b"
    };
    bool result[] = {
            1,
            0,
            1,
            1,
            1,
            1,
            1,
            0,
            1,
            1,
            1,
            1,
            1,
            1,
            1,
            1,
            0,
            0,
            1,
            1,
            1
    };
    Solution0 solution;
    for (int i = 0; i < size(s); i++) {
//        cout <<solution.isMatch(s[i], p[i])<<","<< endl;
        cout << i + 1 << ":" << (solution.isMatch(s[i], p[i]) == result[i]) << endl;
    }
    return 0;
}
