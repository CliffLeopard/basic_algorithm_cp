/**
 * author:CliffLeopard 
 * date:2019/11/19  
 * time:22:19
 * email:precipiceleopard@gmail.com
 * link:https://leetcode.com/problems/integer-to-roman/
 * 难度：简单
 * 确定好每位的四种情况
 */

#include <iostream>
#include <map>

using namespace std;

/**
 * greedy algorithm
 * 每一步都选取最优解  4ms
 * @return
 */

#include <vector>

class Solution {
public:
    string intToRoman(int num) {
        string result = "";
        int len = 13;
        for (int i = 0; i < 13; i++) {
            while (num >= romToInt[i].first) {
                result += romToInt[i].second;
                num -= romToInt[i].first;
            }
        }
        return result;
    }

private:
    vector<pair<int, string>> romToInt = {
            pair<int, string>(1000, "M"),
            pair<int, string>(900, "CM"),
            pair<int, string>(500, "D"),
            pair<int, string>(400, "CD"),
            pair<int, string>(100, "C"),
            pair<int, string>(90, "XC"),
            pair<int, string>(50, "L"),
            pair<int, string>(40, "XL"),
            pair<int, string>(10, "X"),
            pair<int, string>(9, "IX"),
            pair<int, string>(5, "V"),
            pair<int, string>(4, "IV"),
            pair<int, string>(1, "I"),
    };
};

/**
 * 推理的方式
 * 16ms
 */
class Solution2 {
public:
    string intToRoman(int num) {
        string result = "";
        int j = 1000;
        while (num > 0) {
            int now = num / j;
            switch (now) {
                case 0 ... 3:
                    result += string(now, aMap[j]);
                    break;
                case 4:
                    result += aMap[j];
                    result += aMap[j * 5];
                    break;
                case 5 ... 8:
                    result += aMap[j * 5];
                    result += string(now - 5, aMap[j]);
                    break;
                case 9:
                    result += aMap[j];
                    result += aMap[j * 10];
                    break;
            }
            num %= j;
            j = j / 10;
        }
        return result;
    }

private:
    map<int, char> aMap = {
            pair<int, char>(1, 'I'),
            pair<int, char>(5, 'V'),
            pair<int, char>(10, 'X'),
            pair<int, char>(50, 'L'),
            pair<int, char>(100, 'C'),
            pair<int, char>(500, 'D'),
            pair<int, char>(1000, 'M')
    };
};


int main() {
    Solution solution;
    int input[] = {3, 4, 9, 58, 1994, 600, 3392, 1935, 1321, 1451, 1531};
    for (int i = 0; i < size(input); i++)
        cout << solution.intToRoman(input[i]) << endl;
}