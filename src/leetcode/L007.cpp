/**
 * author:CliffLeopard 
 * date:2019/11/16  
 * time:17:30
 * email:precipiceleopard@gmail.com
 * link: https://leetcode.com/problems/reverse-integer/
 * 简单，不做说明。 0ms
 */
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;
#define str_max to_string(INT32_MAX)
class Solution {
public:
    static int reverse(int x) {
        int result = 0;
        if (x == INT32_MIN)
            return 0;
        string temp = to_string(abs(x));
        int length = temp.length();
        std::reverse(temp.begin(), temp.end());
        if (temp.length() == str_max.length()) {
            for (int i = 0; i < length; i++) {
                if (temp[i] > str_max[i]) {
                    return 0;
                }else if(temp[i] < str_max[i]){
                    break;
                }
            }
        }
        stringstream geek(temp);
        geek >> result;
        if (x < 0)
            result = -result;
        return result;
    }
};

int main() {

    cout << INT32_MIN << endl;
    cout << INT32_MAX << endl << endl;
    int demos[] = {
            INT32_MIN + 1,
            INT32_MAX,
            123,
            -123,
            120,
            -1463847412,
            -2147483412
    };
    for (int demo : demos) {
        cout << Solution::reverse(demo) << endl;
    }
}