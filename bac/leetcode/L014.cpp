/**
 * author:CliffLeopard 
 * date:2019/11/20  
 * time:10:11
 * email:precipiceleopard@gmail.com
 * link:https://leetcode.com/problems/longest-common-prefix/
 */

#include <iostream>
#include <vector>

using namespace std;

/**
 * 纵向拉一条线，各个字符串比较
 */
class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        string result = "";
        int n = strs.size();
        if (strs.size() == 0)
            return result;
        for (int i = 0; i < strs[0].length(); i++) {
            for (int j = 1; j < n; j++) {
                if (i > strs[j].length() - 1 || strs[0][i] != strs[j][i])
                    return result;
            }
            result.push_back(strs[0][i]);
        }
        return result;
    }
};

/**
 * 利用字符串排序为逐位排序，则自左边起，字符差异最大的就是两端的字符串。
 */
class Solution2 {
public:
    string longestCommonPrefix(vector<string> &strs) {
        int n = strs.size();
        string result = "";
        if (n == 0)
            return result;
        if (n == 1)
            return strs[0];
        sort(strs.begin(), strs.end());
        string min = strs[0];
        string max = strs[n - 1];
        int m = max.length();
        for (int i = 0; i < min.length(); i++) {
            if (i > m - 1 || min[i] != max[i]) {
                return result;
            }
            result.push_back(min[i]);
        }
        return result;
    }
};

int main() {
    Solution2 solution;
    vector<string> vec = {"flower","flow","flight"};
    sort(vec.begin(), vec.end());
    vector<string>::iterator iterator;
//    for (iterator = vec.begin(); iterator != vec.end(); iterator++)
//        cout << *iterator << "  ";
//    cout << endl;
    cout << solution.longestCommonPrefix(vec) << endl;
}