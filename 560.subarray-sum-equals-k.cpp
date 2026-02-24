/*
 * @lc app=leetcode id=560 lang=cpp
 *
 * [560] Subarray Sum Equals K
 *
 * https://leetcode.com/problems/subarray-sum-equals-k/description/
 *
 * algorithms
 * Medium (46.79%)
 * Likes:    24799
 * Dislikes: 841
 * Total Accepted:    2.3M
 * Total Submissions: 4.9M
 * Testcase Example:  '[1,1,1]\n2'
 *
 * Given an array of integers nums and an integer k, return the total number of
 * subarrays whose sum equals to k.
 * 
 * A subarray is a contiguous non-empty sequence of elements within an
 * array.
 * 
 * 
 * Example 1:
 * Input: nums = [1,1,1], k = 2
 * Output: 2
 * Example 2:
 * Input: nums = [1,2,3], k = 3
 * Output: 2
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 2 * 10^4
 * -1000 <= nums[i] <= 1000
 * -10^7 <= k <= 10^7
 * 
 * 
 */

// @lc code=start
#include <unordered_map>
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        sums.resize(nums.size() + 1, 0);
        for (int i = 0; i < nums.size(); ++i) {
            sums[i + 1] = sums[i];
            sums[i + 1] += nums[i];
        }

        int result = 0;

        m.clear();
        m.insert({0, 1});
        for (int i = 1; i < sums.size(); ++i) {
            int target = sums[i] - k;
            auto found = m.find(target);
            if (found != m.end()) {
                result += found->second;
            }
            found = m.find(sums[i]);
            if (found != m.end()) {
                ++(found->second);
            }
            else {
                m.insert({sums[i], 1});
            }
        }

        #if 0
        for(int i = 0; i < nums.size(); ++i) {
            for (int j = i; j < nums.size(); ++j) {
                if (sumRange(i,j) == k) {
                    ++result;
                }
            }
        }
        #endif
        return result;
    }
    vector<int> sums;
    unordered_map<int,int> m;
};

// [1,-1,0]\n0
// [1,2,3]\n3
// @lc code=end

