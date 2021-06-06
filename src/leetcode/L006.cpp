/**
 * author:CliffLeopard 
 * date:2019/11/16  
 * time:11:27
 * email:precipiceleopard@gmail.com
 * link:https://leetcode.com/problems/zigzag-conversion/
 *
 * 此题计较简单，简单说一下
 * Z字形的图，显然一个图形循环为竖线和去掉两端的45度斜线。loop=2*numRows-1;
 * 为了一次输出，则肯定要按行追加。外层对行数循环。
 * 图形是按loop循环的，显然内层要进行逐次增加loop长度的循环。
 * 观察图形易知，一次循环内除了两端只添加一个元素之外。都是添加两个元素。(两端是竖线和斜线的交集，只添加一次)
 * 两次添加的间隔为底部三角的元素个数。(numRows-1-i)*2= 2*numRows-2-2*i=loop - 2 * i
 */

#include <iostream>
#include<vector>

using namespace std;

class Solution {
public:
    static string convert(string &s, int numRows) {
        int n = s.length();
        if (n <= numRows || numRows == 1) return s;
        string result;
        int loop = 2 * numRows - 2;
        for (int i = 0; i < numRows; i++) {
            for (int j = i; j < n; j += loop) {
                result.push_back(s[j]);
                if (i % (numRows - 1) != 0 && j + loop - 2 * i < n)
                    result.push_back(s[j + loop - 2 * i]);
            }
        }
        return result;
    }

    /**
     * 此题还可以得到完整列的个数
     * @param s
     * @param numRows
     * @return
     * 说明:此题一定程度上是一个数学题。
     * m:图形具有的完整纵列
     * n:图形元素个数
     * r:图形行数(numRows)
     * 则有且仅有两种情况:
     * 1. m*r+(r-2)*m+k1=n;(0<=k1<r)  k1代表最终剩余的是不完整的纵线元素。
     * 2. m*r+(r-2)*(m-1)+k2=n;(0<=k2<r-2) k2代表最后剩余的不完整斜线元素。
     * 1 ==> m=(n-k1)/(2*(r-1)) (0<=k1<r)
     * 2 ==> m=(n+r-k2-2)/(2*r-2)  (0<=k2<r-2)
     * 又因为m,n,r,k1,k2都显然为正整数。
     */
    static int getFullLine(string &s, int numRows) {
        int n = s.length();
        int m = 0;
        for (int i = 0; i < numRows; i++) {
            if (i < numRows - 2 && (n + numRows - i - 2) % (2 * numRows - 2) == 0) {
                m = (n + numRows - i - 2) / (2 * numRows - 2);
                if (m > 0) {
                    break;
                }
            }
            if ((n - i) % (2 * (numRows - 1)) == 0) {
                m = (n - i) / (2 * (numRows - 1));
                if (m > 0) {
                    break;
                }
            }
        }
        return m;
    }
};

int main() {
    string s[] = {
            "PAYPALISHIRING",
            "PAYPALISHIRING",
            "ABCDEFGHIJKLMNO"
    };
    int numRows[] = {3, 4, 5};
    for (int i = 0; i < size(s); i++) {
        cout << Solution::convert(s[i], numRows[i]) << endl;
    }
    return 0;
}
