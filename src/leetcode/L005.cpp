/**
 * author:CliffLeopard
 * date:2019/11/13
 * time:10:21
 * email:precipiceleopard@gmail.com
 * link:https://leetcode.com/problems/longest-palindromic-substring/
 */

#include <iostream>

using namespace std;

/**
 * 难度:简单
 * 典型最大回文串问题
 * 三种种解决方案：
 *  1. 遍历i为回文中心，找到以i为回文中心的最大回文串长度length。比较并更新maxLength。先解决单回文串，再解决双回文串。 效率O(n^2)
 *  2. DP问题:设函数f(i,j),表示s子串substr(i,j)是否回文。
 *      状态转移方程：
 *          f(i,j) = true; condition: f(i+1,j-1) = true && s[i] = s[j]
 *          f(i,j) = true; condition: s[i] = s[j] && j=i+1;
 *          f(i,j) = true; condition: i==j;
 *       则使用i降序，j升序的方式遍历一下，构造一个二维数组即可。
 *       但是此问题使用动态规划效率较低。因为每一个回文串的判断都是基于相邻回文串的判断，不能通过maxLength的大小省略计算。而且二维数组的构造内存占用较大。
 *  3.Manacher 算法
 *    Manacher算法的高效体现在充分利用了回文的对称性，对于一个大回文串，以中心为对称的两边是完全相同的，则不需要重复计算。 关键在于找到局部最大回文串的中心。
 *    什么是局部最大回文串的中心呢？ 设中心p,回文半径length。即p+length的范围内的p'的回文半径如果小于<length,则以p为中心的回文串就是局部最大的了。
 *    为了构造这种中心对称的回文性，Manacher算法首先将双回文串的情况改造为但回文串。这种思想也可以用在算法1中。避免了两种情况的判断。但是内存会增大。
 */

#define MAX  1001
bool dp[MAX][MAX];
class Solution {
public:
    static string longestPalindrome(const string& s) {
        string result1, result2, result3, result4;
        result1 = centerTraverse(s);
        result2 = DP(s);
        result3 = manacher(s);
        result4 = centerTravelManacher(s);
        cout << result1 << endl << result2 << endl << result3 << endl << result4 << endl;
        return result1;
    }

private:
    static string centerTraverse(string s) {

        int n = s.length();
        int maxlength = 1, length = 1;
        int start = 0, i = 0;
        if (n == 0) return "";

//      单回文串
        while (i < n) {
            while (i - length >= 0 && i + length < n && s[i - length] == s[i + length]) {
                length++;
            }
            length--;

            if (2 * length + 1 > maxlength) {
                maxlength = 2 * length + 1;
                start = i - length;
            }
            if (i + maxlength / 2 >= n - 1)
                break;
            i++;
            length = 1;
        }

        i = 0;
        length = 1;

//      双回文串
        while (i + 1 < n) {
            if (s[i] == s[i + 1]) {
                while (i - length >= 0 && i + 1 + length < n && s[i - length] == s[i + 1 + length]) {
                    length++;
                }
                length--;
                if (2 * length + 2 > maxlength) {
                    maxlength = 2 * length + 2;
                    start = i - length;
                }
                if (i + maxlength / 2 >= n - 2)
                    break;
            }
            i++;
            length = 1;
        }
        return s.substr(start, maxlength);
    }

    static string DP(string s) {
        int n = s.length();
        if (n < 1) return "";
        dp[n - 1][n - 1] = true;
        int maxlength = 1, start = 0;

        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (i == j)
                    dp[i][j] = true;
                else if (j == i + 1 && s[i] == s[j]) {
                    dp[i][j] = true;
                    if (2 > maxlength) {
                        maxlength = 2;
                        start = i;

                    }
                } else if (i + 1 < n && dp[i + 1][j - 1] && s[i] == s[j]) {
                    dp[i][j] = true;
                    if (j - i + 1 > maxlength) {
                        maxlength = j - i + 1;
                        start = i;
                    }

                } else {
                    dp[i][j] = false;
                }
            }
        }
        return s.substr(start, maxlength);
    }

    /**
     * manacher 算法
     * @param s
     * @return
     *  比较好理解:当前判断的中心对称点i,在i之前的某个点mostC,拥有最右边的对称半径mostRight。
     *  lp:i关于mostC点的对称点。lp=2*mostC-i;
     *  lc:mostC点的对称左边界。
     *  lengths:记录各个对称点的半径。
     *  lbp:lp的左边届:lbp=lp-lengths[lp]。
     *
     *  显然，当i点位于mostC的对称半径之内时(i<=mostRight)，
     *    1. lp对称范围在mostC的对称半径之内(即lbp>lc)时，lengths[i]=lengths[lp];
     *    2. lp对称范围在mostC的对称半径之外(即lbp<lc)时, lengths[i]=mostRight-i; 否则lbp还会向左扩张。
     *       情况1，2可以联合为lengths[i] = min(lengths[lp],mostRight-i)
     *    3. lp对称范围左边界与lc重合(lbp==lc)时，此时可见是字符串左边的长度限制了lp的半径，而i不受限制，所以i的半径要重新计算(已计算部分可不重新计算)。同算法1
     *  当i点位于mostC的对称半径之外时(i>2*mostC-mostRight):
     *    情况如3.
     *
     */
    static string manacher(string s) {
        int n = s.length();
        if (n == 0) return "";
        if (n == 1) return s;

        int start = 0, maxlength = 1;
        int i;
        int mostRight = 0, mostC = 0, lp, lc = 0;
        char *newStr = new char[2 * n + 1];
        int *lengths = new int[2 * n + 1];
        newStr[0] = '#';
        lengths[0] = 0;
        for (i = 0; i < n; i++) {
            newStr[2 * i + 1] = s[i];
            newStr[2 * i + 2] = '#';
        }
        i = 0;
        while (i < 2 * n + 1) {
            lp = 2 * mostC - i;
            if (i <= mostRight && lp - lengths[lp] > lc) {
                lengths[i] = lengths[lp];
            } else if (i <= mostRight && lp - lengths[lp] < lc) {
                lengths[i] = mostRight - i;
            } else {
                lengths[i] = 1;
                while (i - lengths[i] >= 0 && i + lengths[i] < 2 * n + 1 &&
                       newStr[i - lengths[i]] == newStr[i + lengths[i]])
                    lengths[i]++;
                lengths[i]--;
                if (i + lengths[i] > mostRight) {
                    mostC = i;
                    mostRight = i + lengths[i];
                    lc = 2 * mostC - mostRight;
                }
            }
            if (2 * lengths[i] + 1 > maxlength) {
                maxlength = 2 * lengths[i] + 1;
                start = i - lengths[i];
            }
            if (i + maxlength / 2 >= 2 * n)
                break;
            i++;
        }
        return s.substr(start / 2, maxlength / 2);
    }

    static string centerTravelManacher(string s) {
        int n = s.length();
        int maxlength = 0, center = 0, start = 0;
        int right = 0, rcenter = 0, rcl = 0, sp;
        int *length = new int[n];
        string result;

        if (n == 0) return "";
        if (n == 1) return s.substr(0, 1);
        length[0] = 0;
        //单回文串
        while (center < n) {
            sp = 2 * rcenter - center;
            if (center <= right && rcl < sp - length[sp]) {
                length[center] = length[sp];
            } else if (center <= right && rcl > sp - length[sp]) {
                length[center] = right - center;
            } else {
                length[center] = 1;
                while (center - length[center] >= 0 && center + length[center] < n &&
                       s[center - length[center]] == s[center + length[center]]) {
                    length[center]++;
                }
                length[center]--;
            }
            if (2*length[center]+1 > maxlength) {
                maxlength = 2*length[center]+1;
                start = center - length[center];
            }
            if (center + length[center] > right) {
                rcenter = center;
                right = center + length[center];
                rcl = 2 * rcenter - right;
            }
            center++;
        }
        //双回文串
        center = 0;
        while (center + 1 < n) {
            if (s[center] == s[center + 1]) {
                length[center] = 1;
                while (center - length[center] >= 0 && center + 1 + length[center] < n &&
                       s[center - length[center]] == s[center + 1 + length[center]]) {
                    length[center]++;
                }
                length[center]--;
                if (2*length[center]+2> maxlength) {
                    maxlength =    2*length[center]+2;
                    start = center - length[center];
                }
                if (center + maxlength / 2 >= n - 2)
                    break;
            }
            center++;
        }
        return s.substr(start, maxlength);
    }
};

int main() {
    string s[] = {
            "babad",
            "cbbd",
            "adebedac",
            "abacab",
            "babadada"
    };
    for (const auto & i : s) {
        Solution::longestPalindrome(i);
        cout << endl;
    }
    return 0;
}