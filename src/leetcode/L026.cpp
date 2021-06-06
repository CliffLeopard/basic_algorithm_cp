/**
 * author:CliffLeopard 
 * date:2019/11/26  
 * time:14:37
 * email:precipiceleopard@gmail.com
 * link:https://leetcode.com/problems/remove-duplicates-from-sorted-array/
 */
#include <iostream>
#include <vector>

using namespace std;

/**
 * 一次循环，以i来记录不同值的位置。
 * 12ms 99.93%
 */
class Solution {
public:
    static int removeDuplicates(vector<int> &nums) {
        int n = nums.size();
        if (n == 0 || n == 1)
            return n;
        int i = 0;
        for (int j = 1; j < n; j++) {
            if (nums[j] != nums[i]) {
                nums[++i] = nums[j];
            }
        }
        return i + 1;
    }
};

/**
 * 思路比较清晰的解法，但是效率太低了。
 */
class Solution2 {
public:
    static int removeDuplicates(vector<int> &nums) {
        int n = nums.size();
        if (n == 0 || n == 1)
            return n;
        int lastSingle = 0;
        int repeat = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[lastSingle]) {
                nums[i] = nums[0] - 1;
                repeat++;
            } else {
                lastSingle = i;
            }
        }
        for (int i = 1; i <= n - repeat - 1; i++) {
            if (nums[i] == nums[0] - 1) {
                for (int j = i + 1; j < n; j++) {
                    if (nums[j] != nums[0] - 1) {
                        nums[i] = nums[j];
                        nums[j] = nums[0] - 1;
                        break;
                    }
                }
            }
        }
        return n - repeat;
    }
};

int main() {
    vector<int> input = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int result = Solution::removeDuplicates(input);
    auto iter = input.begin();
    cout << "result:" << result << endl;
    while (iter != input.end()) {
        cout << *iter << " ";
        iter++;
    }
    cout << endl;

}