/**
 * author:CliffLeopard 
 * date:2019/11/20  
 * time:09:13
 * email:precipiceleopard@gmail.com
 * link:https://leetcode.com/problems/roman-to-integer/
 * 与12题一脉相承，简单
 */
#include <iostream>
#include <map>

using namespace std;

/**
 * 按照转换定义写。 IV = V-I
 */
class Solution {
public:
    int romanToInt(string s) {
        int n = s.length();
        if(n == 1)
            return aMap[s[0]];

        int result  = aMap[s[n-1]];
        for(int i=n-2;i>=0;i--){
            int now = aMap[s[i]];
            if(aMap[s[i+1]]>now)
                result-=now;
            else
                result+=now;
        }
        return result;
    }

private:
    map<char, int> aMap = {
            pair<char, int>('I', 1),
            pair<char, int>('V', 5),
            pair<char, int>('X', 10),
            pair<char, int>('L', 50),
            pair<char, int>('C', 100),
            pair<char, int>('D', 500),
            pair<char, int>('M', 1000)
    };
};

/**
 * 一次判断两位，因为频繁截取字符串，效率较低
 */
class Solution2 {
public:
    int romanToInt(string s) {
        int n = s.length();
        int result = 0;
        if (n == 1)
            return aMap[s];
        int j = 0;
        while (j < n - 1) {
            string temp = s.substr(j, 2);
            if (aMap.find(temp) != aMap.end()) {
                result += aMap[temp];
                j += 2;
            } else {
                result += aMap[string(1, s[j])];
                j++;
            }
        }
        if (j == n - 1)
            result += aMap[string(1, s[j])];
        return result;
    }

private:
    map<string, int> aMap = {
            pair<string, int>("I", 1),
            pair<string, int>("IV", 4),
            pair<string, int>("V", 5),
            pair<string, int>("IX", 9),
            pair<string, int>("X", 10),
            pair<string, int>("XL", 40),
            pair<string, int>("L", 50),
            pair<string, int>("XC", 90),
            pair<string, int>("C", 100),
            pair<string, int>("CD", 400),
            pair<string, int>("D", 500),
            pair<string, int>("CM", 900),
            pair<string, int>("M", 1000)
    };
};

int main() {
    string input[] = {
            "III",
            "IV",
            "IX",
            "LVIII",
            "MCMXCIV",
            "DC",
            "MMMCCCXCII",
            "MCMXXXV",
            "MCCCXXI",
            "MCDLI",
            "MDXXXI"
    };
    Solution solution;
    for (int i = 0; i < size(input); i++)
        cout << solution.romanToInt(input[i]) << endl;
    return 0;
}