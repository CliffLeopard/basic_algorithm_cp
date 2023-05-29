/**
 * author:CliffLeopard 
 * date:2019/11/27  
 * time:01:07
 * email:precipiceleopard@gmail.com
 * link: https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/
 */
#include "iostream"
using namespace std;
class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;
        if (haystack.empty()) return -1;
        if (haystack.length() == needle.length()) {
            if (haystack == needle) return 0;
            return -1;
        }
        vector<int> nextArray(needle.length(), 0);
        generateNext(nextArray, needle);
        int i = 0, j =0;
        while(i<haystack.length() && j<(int)needle.length()) {
            if (j==-1 || haystack[i]==needle[j]) {
                i++;
                j++;
            }
            else j = nextArray[j];
        }
        if (j == needle.length()) return i-j;
        return -1;
    }
private:
    void generateNext(vector<int> &nextArray, string needle) {
        nextArray[0] = -1;
        int k = -1, j = 0;
        while(j < needle.length()-1) {
            if (k==-1 || needle[k]==needle[j]) {
                k++;
                j++;
                if (needle[j] != needle[k]) nextArray[j] = k;
                else nextArray[j] = nextArray[k];
            }
            else k = nextArray[k];
        }
    }
};