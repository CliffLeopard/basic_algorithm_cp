/**
 * author:CliffLeopard 
 * date:2019/11/19  
 * time:06:47
 * email:precipiceleopard@gmail.com
 * link:https://leetcode.com/problems/palindrome-number/
 */

#include <iostream>

using namespace std;

/**
 * 此方法12ms
 */
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        if (x < 10)
            return true;

        unsigned long j = 1;
        int temp = 1;
        while (x >= j * 10) {
            if (x == j) {
                return false;
            }
            temp++;
            j = j * 10;
        }
        int x1 = x;
        for (int i = 1; i <= temp / 2; i++) {
            if (x1 / j != x % 10)
                return false;
            x1 = x1 % j;
            x = x / 10;
            j /= 10;
        }
        return true;
    }
};

/**
 * 此方法8ms
 */
class Solution2 {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        if (x < 10)
            return true;
        if (x % 10 == 0)
            return false;
        unsigned long temp = x % 10 * 11;
        unsigned long j = 10;
        int tail = x % 10;
        while (temp < x) {
            j *= 10;
            unsigned long centerTemp = (temp - tail) * 10 + (x - tail) % j + tail;
            if (centerTemp == x)
                return true;
            else if (centerTemp > x)
                return false;
            temp = (temp - tail) * 100 + ((x - tail) % j) * 10;
            tail = x % j;
            temp += tail;
        }
        return temp == x;
    }
};

int main() {
    int input[] = {
            12321,
            123321,
            10101
    };
    Solution2 solution;
    for (int i = 0; i < size(input); i++)
        cout << solution.isPalindrome(input[i]) << endl;
    return 0;
}