/**
 * author:CliffLeopard 
 * date:2019/11/17  
 * time:04:18
 * email:precipiceleopard@gmail.com
 * link:https://leetcode.com/problems/regular-expression-matching/
 */

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {

        p = simplify(p, s);

        unsigned long s_length = s.length(), p_length = p.length();
        unsigned long fist_position = 0;
        unsigned long position;

        if (p_length > 0 && (p[0] == '*' || p.rfind("**") != string::npos))
            return false;

        if (s_length == 0) {
            if (p_length == 0)
                return true;
            int pt = p.find_first_not_of('*');
            while (pt != string::npos) {
                if (pt == p_length - 1 || p[pt + 1] != '*')
                    return false;
                pt = p.find_first_not_of('*', pt + 1);
            }
            return true;
        }

        while (true) {
            position = min(p.find_first_of(s[0], fist_position), p.find_first_of('.', fist_position));
            if (position == string::npos)
                return false;
            else {
                fist_position = position + 1;
                if (!isPatternEmpty(p.substr(0, position)))
                    return false;
            }
            if (p[position] != '*')
                position++;
            unsigned long i = 1;
            for (i; i < s_length && position < p_length; i++) {
                if (p[position] == '*') {
                    if (p[position - 1] != s[i] ) { //&& p[position - 1] != '.'
                        position++;
                        i--;
                    }
                } else {
                    if (p[position] != s[i] && p[position] != '.') {
                        if (position + 1 < p_length && p[position + 1] == '*') {
                            position += 2;
                            i--;
                        } else {
                            break;
                        }
                    } else if (p[position] != '*')
                        position++;
                }
            }
            if (i == s_length) {
                if (position >= p_length || isPatternEmpty(p.substr(position, p_length - position)))
                    return true;
            }
        }
    }

private:
    bool isPatternEmpty(string p) {
        if (p.empty())
            return true;
        if (p[p.length() - 1] != '*')
            return false;
        for (int i = 0; i < p.length() - 1; i++) {
            if (p[i] != '*' && p[i + 1] != '*')
                return false;
        }
        return true;
    }

    string simplify(string p, string &s) {
        int n = p.length();
        string temp = p;
        if (n <= 1) return p;
        int j = 0;
        while (j < n && n > 0) {
            bool flag = true;
            if (j + 1 < n && p[j] != '.' && s.find(p[j]) == string::npos && p[j + 1] == '*') {
                p.erase(j, 2);
                n -= 2;
                flag = false;
            }
            if (j >= 2 && p[j] != '.' && p[j - 1] == '*' && p[j] == p[j - 2]) {
                p.erase(j, 1);
                n--;
                flag = false;
            }
            if (j + 2 < n && p[j] != '.' && p[j] == p[j + 1] && p[j + 2] == '*') {
                p.erase(j, 1);
                flag = false;
            }
            if (flag)
                j++;
            else
                j = 0;
        }

//        cout << endl << "simple:" << p << endl;
        return p;
    }
};

int main() {
    Solution solution;
    string s[] = {
//            "aa",
//            "aa",
//            "ab",
//            "aab",
//            "mississippi",
//            "aab",
//            "aaa",
//            "aaa",
//            "aaa",
//            "aaa",
//            "ab",
//            "a",
//            "",
//            "fas",
            "aasdfasdfasdfasdfas"
    };
    string p[] = {
//            "a",
//            "a*",
//            ".b",
//            "c*a*b",
//            "mis*is*ip*.",
//            "c*aab*",
//            "a*a",
//            "ac*b*a*",
//            "ab*a",
//            "ab*a*c*a",
//            ".*",
//            ".*..a*",
//            ".*",
//            "f.*s",
            "aasdf.*asdf.*asdf.*asdf.*s"
    };
    for (int i = 0; i < size(s); i++) {
        cout << i + 1 << " :  " << solution.isMatch(s[i], p[i]) << endl;
    }

//    string s = "";
//    string p1 = "c";
//    string p2 = "abc*";
//    cout << string::npos << endl;
//    cout << p2.find_first_of("b", 1) << endl;


    return 0;
}