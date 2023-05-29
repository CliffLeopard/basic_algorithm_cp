/**
 * author:CliffLeopard 
 * date:2019/11/27  
 * time:01:08
 * email:precipiceleopard@gmail.com
 * link:https://leetcode.com/problems/divide-two-integers/
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == 0) return 0;
        if (divisor == 1) return dividend;
        if (divisor == -1) return dividend == INT32_MIN ? INT32_MAX : -dividend;

        bool negativeFlag = (dividend > 0) ^ (divisor > 0);
        long tempDividend = abs(0L + dividend);
        long tempDivisor = abs(0L + divisor);
        if (tempDivisor > tempDividend) return 0;

        long times = 0;
        long nowTimes, temp;
        while (tempDividend >= tempDivisor) {
            temp = tempDivisor;
            nowTimes = 1;
            while (tempDividend >= temp) {
                temp <<= 1;
                nowTimes <<= 1;
            }
            times += nowTimes >> 1;
            tempDividend -= temp >> 1;
        }
        if (!negativeFlag && times >= INT32_MAX)
            return INT32_MAX;
        else if (negativeFlag && -times <= INT32_MIN)
            return INT32_MIN;
        return (int) (negativeFlag ? -times : times);
    }
};