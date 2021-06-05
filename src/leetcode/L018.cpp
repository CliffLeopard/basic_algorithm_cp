/**
 * author:CliffLeopard 
 * date:2019/11/21  
 * time:14:56
 * email:precipiceleopard@gmail.com
 * link:https://leetcode.com/problems/4sum/
 * 4ms 99.83%
 * 解题方法和3sum大同小异，注意剪枝
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target) {
        vector<vector<int>> result;
        int n = nums.size();
        if (n < 4) return result;
        sort(nums.begin(), nums.end());
        for (int begin = 0; begin <= n - 4; begin++) {
            if (begin > 0 && nums[begin - 1] == nums[begin]) continue;

            if(nums[begin]+nums[begin+1]+nums[begin+2]+nums[begin+3]>target) return result;
            if(nums[begin]+nums[n-1]+nums[n-2]+nums[n-3]<target) continue;

            for (int i = begin + 1; i <= n - 3; i++) {
                if (i > begin + 1 && nums[i - 1] == nums[i]) continue;

                if(nums[begin]+nums[i]+nums[i+1]+nums[i+2]>target) break;
                if(nums[begin]+nums[i]+nums[n-1]+nums[n-2]<target) continue;

                int left = i + 1;
                int right = n - 1;
                while (left < right) {
                    int sum = nums[begin] + nums[i] + nums[left] + nums[right];
                    if (sum > target) {
                        right--;
                    } else if (sum < target) {
                        left++;
                    } else {
                        result.push_back({nums[begin], nums[i], nums[left], nums[right]});

                        left++;
                        while (left < right && nums[left - 1] == nums[left]) left++;

                        right--;
                        while (left < right && nums[right + 1] == nums[right]) right--;
                    }
                }
            }
        }
        return result;
    }
};

int main() {
    vector<int> nums = {
            0, 0, 0, 0
    };

    Solution solution;
    vector<vector<int>> result = solution.fourSum(nums, 0);
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << "  ";
        }
        cout << endl;
    }
    return 0;
}