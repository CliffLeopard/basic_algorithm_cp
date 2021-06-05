/**
 * author:CliffLeopard 
 * date:2019/11/20  
 * time:13:38
 * email:precipiceleopard@gmail.com
 * link:https://leetcode.com/problems/letter-combinations-of-a-phone-number/
 *
 * 递归实现
 * 关键点:A={a,b,c} B={d,e,f}, 求A，B的组合时，B.size = b_len,A.size=a_len
 * 分别从B中选取b_len-1个，分别拼接到A中的每一个元素上，将结果向后拼接。
 * 最后在将A中的前A_len个元素原地拼接上B中第b_len个元素。
 * 这样做是为了防止A中元素原地拼接之后影响后面拼接的组合。
 */
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        int n = digits.length();
        if (n == 0)
            return result;
        else {
            string now = number_array[digits[0] - '2'];
            for (int i = 0; i < now.length(); i++)
                result.push_back(string(1, now[i]));
        }
        return combineTwoSet(result, digits, 1, n);
    }

private:
    vector<string> number_array = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    vector<string> combineTwoSet(vector<string> &result, string &input, int cur, int n) {
        if (cur >= n)
            return result;
        string now = number_array[input[cur] - '2'];
        int now_len = now.length();
        int m = result.size();

        for (int j = 0; j < now_len; j++) {
            for (int i = 0; i < m; i++) {
                if (j == now_len - 1)
                    result[i].push_back(now[j]);
                else
                    result.push_back(result[i] + now[j]);
            }
        }
        return combineTwoSet(result, input, ++cur, n);
    }
};

/**
 * 深度优先遍历DFS(例如"2，3")
 *             (2)
 *              |
 *        a     b     c
 *        |     |     |
 *       (3)   (3)   (3)
 *        |     |     |
 *      d e f d e f d e f
 * 从根结点到叶子结点的每一条路径都是一个组合序列。
 *
 * 算法实现上细节不太相同，大体一致
 */
class Solution2 {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        int n = digits.length();
        if (n == 0)return result;
        string root = number_array[digits[0] - '2'];
        for (int i = 0; i < root.length(); i++)
            result.push_back(string(1, root[i]));
        return combineTwoSet(result, digits, 1);
    }

private:
    vector<string> number_array = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    vector<string> combineTwoSet(vector<string> &result, string &digits, int cur) {
        if (cur >= digits.length())
            return result;
        string node = number_array[digits[cur] - '2'];
        int n = result.size();
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < node.length(); j++) {
                result.push_back(result[i] + node[j]);
            }
            result[i].push_back(node[0]);
        }
        return combineTwoSet(result,digits,++cur);
    }

};

int main() {
    vector<string> input = {
            "234"
    };
    Solution2 solution;
    vector<string>::iterator iterator;
    for (iterator = input.begin(); iterator != input.end(); iterator++) {
        vector<string> result = solution.letterCombinations(*iterator);
        for (int i = 0; i < result.size(); i++)
            cout << result[i] << "  ";
        cout << endl;
    }
}