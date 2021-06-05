/**
 * author:CliffLeopard 
 * date:2020/1/8  
 * time:14:54
 * email:precipiceleopard@gmail.com
 * link:
 */
#include<iostream>

using namespace std;

#include "string"
#include "vector"

#define  MAXSIZE 1000

class KMP {
public:
    int index1(string s, string t, int pos) {
        int len_s = s.length(), len_t = t.length();
        int i = 0, j = 0;
        while (i < len_s && j < len_t) {
            if (s[i] == t[j]) {
                i++;
                j++;
            } else {
                i = i - j + 1;
                j = 0;
            }
        }
        return i - j;
    }

    int index2(string haystack, string needle) {
        if (needle.empty()) return 0;
        if (haystack.empty()) return -1;
        if (haystack.length() == needle.length()) {
            if (haystack == needle) return 0;
            return -1;
        }
        vector<int> nextArray(needle.length(), 0);
        generateNext(nextArray, needle);
        int i = 0, j = 0;
        while (i < haystack.length() && j < (int) needle.length()) {
            if (j == -1 || haystack[i] == needle[j]) {
                i++;
                j++;
            } else j = nextArray[j];
        }
        if (j == needle.length()) return i - j;
        return -1;
    }

    void generateNext(vector<int> &nextArray, string needle) {
        nextArray[0] = -1;
        int k = -1, j = 0;
        while (j < needle.length() - 1) {
            if (k == -1 || needle[k] == needle[j]) {
                k++;
                j++;
                if (needle[j] != needle[k]) nextArray[j] = k;
                else nextArray[j] = nextArray[k];
            } else k = nextArray[k];
        }
    }

    void getNextVal(string t, int *next) {
        int j = 0, k = -1, len_t = t.length();
        next[0] = -1;
        while (j < t.length() - 1) {
            if (k == -1 || t[j] == t[k]) {
                j++;
                k++;
                if (t[j] == t[k])
                    next[j] = next[k];
                else
                    next[j] = k;
            } else {
                k = next[k];
            }
        }
    }

    int index3(string s, string t) {
        int len_s = s.length();
        int len_t = t.length();
        int *next = new int[len_t];
        getNextVal(t, next);
        int i = 0, j = 0;
        while (i < len_s && j < len_t) {
            if (s[i] == t[j]) {
                i++;
                j++;
            } else {
                j = next[j];
            }
        }
        if (j == len_t) return i - j;
        else
            return -1;
    }
};

int main() {
    KMP kmp;
    string s = "hello";
    string t = "ll";
//    cout << "index1:" << kmp.index1("", "", 0) << endl;
    cout << "index2:" << kmp.index2("", "") << endl;
}